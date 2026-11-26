#include "RoomClimateController.h"
#include "Types.h"

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

namespace
{
    constexpr std::size_t SIZE_PAYLOAD = 32;
    constexpr std::size_t SIZE_TOPIC = 64;
    char topic[SIZE_TOPIC];
    char payload[SIZE_PAYLOAD];
    constexpr Milliseconds OTA_REQUEST_READ_WINDOW_MS = 2000;
    constexpr Milliseconds OTA_REQUEST_POLL_INTERVAL_MS = 50;
}

RoomClimateController::RoomClimateController(ISht31SensorDriver& sht31SensorDriver, IBatteryDriver& batteryDriver, WiFiConnectionManager& wifiConnectionManager, MqttClientService& mqttClientService, MqttMeasurementPublisher& mqttMeasurementPublisher, FirmwareUpdateService& firmwareUpdateService, MqttOtaRequestReader& mqttOtaRequestReader, MqttOtaStatusPublisher& mqttOtaStatusPublisher, MqttFirmwareVersionPublisher& mqttFirmwareVersionPublisher, PowerManager& powerManager) : sht31SensorDriver(sht31SensorDriver), batteryDriver(batteryDriver), wifiConnectionManager(wifiConnectionManager), mqttClientService(mqttClientService), mqttMeasurementPublisher(mqttMeasurementPublisher), firmwareUpdateService(firmwareUpdateService), mqttOtaRequestReader(mqttOtaRequestReader), mqttOtaStatusPublisher(mqttOtaStatusPublisher), mqttFirmwareVersionPublisher(mqttFirmwareVersionPublisher), powerManager(powerManager), temperatureSensor(sht31SensorDriver), humiditySensor(sht31SensorDriver), batterySensor(batteryDriver), sensorCoordinator(temperatureSensor, humiditySensor, batterySensor) {}

void RoomClimateController::init()
{
    // NOTE: Wi-Fi must currently be initialized before I2C.
    // The root cause of this dependency is still unknown.
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
            if (mqttClientService.readMessage(topic, SIZE_TOPIC, payload, SIZE_PAYLOAD))
            {
                if (mqttOtaRequestReader.processMessage(topic, payload)) break;
            }

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