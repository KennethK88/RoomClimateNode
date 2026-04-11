#include "StateMachine.h"

SystemState StateMachine::calculateState(const ValidationResult& validationResult, const ThresholdResult& thresholdResult)
{
    bool allValidationResultsOk = validationResult.temperatureValid && validationResult.humidityValid && validationResult.coValid;
    bool allThresholdResultsOk = !(thresholdResult.temperatureTooHigh || thresholdResult.temperatureTooLow ||
                                    thresholdResult.humidityTooHigh || thresholdResult.humidityTooLow ||
                                    thresholdResult.coTooHigh);

    if(!allValidationResultsOk) return SystemState::Error;
    else if(allValidationResultsOk && !allThresholdResultsOk) return SystemState::Warning;
    return SystemState::Normal;
}