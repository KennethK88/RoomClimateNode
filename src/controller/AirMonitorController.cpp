#include "controller/AirMonitorController.h"

void AirMonitorController::init()
{
    buzzerDriver.init();
    ledDriverNormal.init();
    ledDriverWarning.init();
    ledDriverError.init();
    oledDriver.init();
    thermistorDriver.init();
    humidityDriver.init();
    coDriver.init();
    distanceDriver.init();
}

void AirMonitorController::update()
{
    const Measurements measurements = sensorCoordinator.readAllSensors();
    const ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    const ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);
    const SystemState systemState = stateMachine.calculateState(validationResults, thresholdResults);
    const bool displayActive = displayPolicy.isDisplayActive(measurements, validationResults);
    displayController.updateDisplay(measurements, systemState, displayActive);
    alarmController.updateAlarm(systemState);
    ledController.updateLeds(systemState);
}