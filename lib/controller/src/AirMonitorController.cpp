#include <AirMonitorController.h>
#include <Arduino.h>

void AirMonitorController::init()
{
    // NOTE: Aktuell muss Wlan vor I2C initialisiert werden. Ursache unklar.
    wifiConnectionManager.init();
    wifiConnectionManager.connect();
    mqttClientService.init();
    mqttClientService.connect();
    sht31SensorDriver.init();
    batteryDriver.init();
}

void AirMonitorController::update()
{
    wifiConnectionManager.reconnect();
    mqttClientService.reconnect();
    sht31SensorDriver.readMeasurements();
    batteryDriver.readVoltage();
    const Measurements measurements = sensorCoordinator.readAllSensors();
    const ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    const SystemState systemState = stateMachine.calculateState(validationResults);
    measurementPublisher.publish(measurements);
    delay(1000);
    powerManager.enterDeepSleep();
}