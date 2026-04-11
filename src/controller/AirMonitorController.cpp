#include "controller/AirMonitorController.h"

void AirMonitorController::init()
{
    compositeAlarmOutput.add(&buzzerDriver);
    compositeAlarmOutput.add(&ledDriver);
    buzzerDriver.init();
    ledDriver.init();
    oledDriver.init();
}

void AirMonitorController::update()
{
    const Measurements measurements = sensorCoordinator.readAllSensors();
    const ValidationResult validationResult = sensorValidator.validateAllSensors(measurements);
    const ThresholdResult thresholdResult = thresholdEvaluator.evaluateAllSensors(measurements, validationResult);
    const SystemState systemState = stateMachine.calculateState(validationResult, thresholdResult);
    displayController.updateDisplay(measurements, systemState);
    alarmController.updateAlarm(systemState);
}