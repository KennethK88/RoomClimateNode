#include "StateMachine.h"

SystemState StateMachine::calculateState(const ValidationResults& validationResults)
{
    bool allValidationResultsOk = validationResults.temperatureValid && validationResults.humidityValid && validationResults.batteryLevelValid;

    if(!allValidationResultsOk) return SystemState::Error;
    return SystemState::Normal;
}