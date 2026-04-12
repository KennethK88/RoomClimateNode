#pragma once
#include "data/ThresholdResults.h"
#include "data/ValidationResults.h"
#include "utils/SystemState.h"

class StateMachine
{
    public:
        StateMachine() = default;
        SystemState calculateState(const ValidationResults& validationResult, const ThresholdResults& thresholdResult);
};