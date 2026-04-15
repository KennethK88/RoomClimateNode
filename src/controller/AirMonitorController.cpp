#include "controller/AirMonitorController.h"

void AirMonitorController::init()
{
    compositeAlarmOutput.add(&buzzerDriver);
    compositeAlarmOutput.add(&ledDriver);
    buzzerDriver.init();
    ledDriver.init();
    oledDriver.init();
    thermistorDriver.init();
}

void AirMonitorController::update()
{
    const Measurements measurements = sensorCoordinator.readAllSensors();
    const ValidationResults validationResult = sensorValidator.validateAllSensors(measurements);
    const ThresholdResults thresholdResult = thresholdEvaluator.evaluateAllSensors(measurements, validationResult);
    const SystemState systemState = stateMachine.calculateState(validationResult, thresholdResult);
    displayController.updateDisplay(measurements, systemState);
    alarmController.updateAlarm(systemState);
}