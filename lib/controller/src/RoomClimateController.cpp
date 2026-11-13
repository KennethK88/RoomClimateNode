#include "RoomClimateController.h"
#include "Types.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

namespace
{
    constexpr Milliseconds OTA_REQUEST_READ_WINDOW_MS = 2000;
    constexpr Milliseconds OTA_REQUEST_POLL_INTERVAL_MS = 50;
}

void RoomClimateController::init()
{
    // NOTE: Aktuell muss Wlan vor I2C initialisiert werden. Ursache unklar.
    wifiConnectionManager.init();
    mqttClientService.init();
    sht31SensorDriver.init();
    batteryDriver.init();
    
}

void RoomClimateController::update()
{
    wifiConnectionManager.connect();
    if (!wifiConnectionManager.isConnected())
        {
            powerManager.enterDeepSleep();
            return;
        }
    mqttClientService.connect(); 
    if (!mqttClientService.isConnected())
    {
        powerManager.enterDeepSleep();
        return;
    }
    mqttOtaStatusPublisher.publishWindowClosed();
    mqttFirmwareVersionPublisher.publishFirmwareVersion();
    if (mqttOtaRequestReader.subscribe())
    {
        const Milliseconds startTime = millis();
        while ((millis() - startTime) < OTA_REQUEST_READ_WINDOW_MS)
        {
            if (mqttOtaRequestReader.update()) break;
            vTaskDelay(pdMS_TO_TICKS(OTA_REQUEST_POLL_INTERVAL_MS));
        }

        if (mqttOtaRequestReader.isOtaRequested())
        {
            if (firmwareUpdateService.init())
            {
                mqttOtaStatusPublisher.publishWindowOpen();
                firmwareUpdateService.runMaintenanceWindow();
                mqttOtaStatusPublisher.publishWindowClosed();
            }
        }        
    }

    sht31SensorDriver.readMeasurements();
    batteryDriver.readVoltage();
    const Measurements measurements = sensorCoordinator.readAllSensors();
    const ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    const SystemState systemState = stateMachine.calculateState(validationResults);
    mqttMeasurementPublisher.publish(measurements);
    mqttClientService.disconnect();
    powerManager.enterDeepSleep();
}