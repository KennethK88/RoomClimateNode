#pragma once
#include "data/ThresholdResult.h"
#include "data/ValidationResult.h"
#include "utils/SystemState.h"

class StateMachine
{
    public:
        StateMachine() = default;
        SystemState calculateState(const ValidationResult& validationResult, const ThresholdResult& thresholdResult);
};