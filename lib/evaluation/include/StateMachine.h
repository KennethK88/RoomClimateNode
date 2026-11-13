#pragma once

#include "ValidationResults.h"
#include "SystemState.h"

class StateMachine
{
    public:
        StateMachine() = default;
        SystemState calculateState(const ValidationResults& validationResults);
};