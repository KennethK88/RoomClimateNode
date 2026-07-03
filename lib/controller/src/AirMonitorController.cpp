#include <AirMonitorController.h>

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
    sht31SensorDriver.readMeasurements();
    batteryDriver.readVoltage();
    const Measurements measurements = sensorCoordinator.readAllSensors();
    const ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    const SystemState systemState = stateMachine.calculateState(validationResults);
    measurementPublisher.publish(measurements);
    powerManager.enterDeepSleep();
}