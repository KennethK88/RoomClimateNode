#include <StateMachine.h>

SystemState StateMachine::calculateState(const ValidationResults& validationResults, const ThresholdResults& thresholdResult)
{
    bool allValidationResultsOk = validationResults.temperatureValid && validationResults.humidityValid && validationResults.coValid;
    bool allThresholdResultsOk = !(thresholdResult.temperatureTooHigh || thresholdResult.temperatureTooLow ||
                                    thresholdResult.humidityTooHigh || thresholdResult.humidityTooLow ||
                                    thresholdResult.coTooHigh);

    if(!allValidationResultsOk) return SystemState::Error;
    else if(allValidationResultsOk && !allThresholdResultsOk) return SystemState::Warning;
    return SystemState::Normal;
}