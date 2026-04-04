#pragma once
#include "Measurements.h"
#include "SystemState.h"

class DisplayController
{
    public:
        DisplayController() = default;
        void updateDisplay(const Measurements& measurements, SystemState systemState);
};