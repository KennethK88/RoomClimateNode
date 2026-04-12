#pragma once
#include "data/ThresholdResults.h"
#include "data/ValidationResult.h"
#include "utils/SystemState.h"

class StateMachine
{
    public:
        StateMachine() = default;
        SystemState calculateState(const ValidationResult& validationResult, const ThresholdResults& thresholdResult);
};