#include "AirMonitorController.h"
#include "Types.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

namespace
{
    constexpr Milliseconds OTA_REQUEST_READ_WINDOW_MS = 2000;
    constexpr Milliseconds OTA_REQUEST_POLL_INTERVAL_MS = 50;
}

void AirMonitorController::init()
{
    // NOTE: Aktuell muss Wlan vor I2C initialisiert werden. Ursache unklar.
    wifiConnectionManager.init();
    mqttClientService.init();
    sht31SensorDriver.init();
    batteryDriver.init();
    
}

void AirMonitorController::update()
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
                firmwareUpdateService.runMaintenanceWindow();
                powerManager.enterDeepSleep();
                return;
            }
        }        
    }

    sht31SensorDriver.readMeasurements();
    batteryDriver.readVoltage();
    const Measurements measurements = sensorCoordinator.readAllSensors();
    const ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    const SystemState systemState = stateMachine.calculateState(validationResults);
    measurementPublisher.publish(measurements);
    powerManager.enterDeepSleep();
}