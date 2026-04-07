#include "AirMonitorController.h"

void AirMonitorController::init()
{
    compositeAlarmOutput.add(&buzzerDriver);
    compositeAlarmOutput.add(&ledDriver);
    buzzerDriver.init();
    ledDriver.init();
}

void AirMonitorController::update()
{
    Measurements measurements = sensorCoordinator.readAllSensors();
    ValidationResult validationResult = sensorValidator.validateAllSensors(measurements);
    ThresholdResult thresholdResult = thresholdEvaluator.evaluateAllSensors(measurements, validationResult);
    SystemState systemState = stateMachine.calculateState(validationResult, thresholdResult);
    displayController.updateDisplay(measurements, systemState);
    alarmController.updateAlarm(systemState);
}