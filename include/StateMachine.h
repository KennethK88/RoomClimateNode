#pragma once
#include "ThresholdResult.h"
#include "ValidationResult.h"
#include "SystemState.h"

class StateMachine
{
    public:
        StateMachine() = default;
        SystemState calculateState(const ValidationResult& validationResult, const ThresholdResult& thresholdResult);
};