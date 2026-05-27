#include <AirMonitorController.h>

void AirMonitorController::init()
{
    alarmOutput.init();
    ledOutputNormal.init();
    ledOutputWarning.init();
    ledOutputError.init();
    displayOutput.init();
    sensorDriverThermistor.init();
    sensorDriverHumidity.init();
    sensorDriverCo.init();
    sensorDriverDistance.init();
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