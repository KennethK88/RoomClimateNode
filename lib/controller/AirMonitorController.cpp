#include <AirMonitorController.h>

void AirMonitorController::init()
{
    // NOTE: Aktuell muss Wlan vor I2C initialisiert werden. Ursache unklar.
    connectionManager.init();
    connectionManager.connect();
    sht31SensorDriver.init();
}

void AirMonitorController::update()
{
    sht31SensorDriver.readMeasurements();
    const Measurements measurements = sensorCoordinator.readAllSensors();
    const ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    const SystemState systemState = stateMachine.calculateState(validationResults);
}