#include <AirMonitorController.h>

void AirMonitorController::init()
{
    sensorDriverThermistor.init();
    sensorDriverHumidity.init();
}

void AirMonitorController::update()
{
    const Measurements measurements = sensorCoordinator.readAllSensors();
    const ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    const SystemState systemState = stateMachine.calculateState(validationResults);
}