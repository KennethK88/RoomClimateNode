#pragma once
#include "data/Measurements.h"
#include "utils/SystemState.h"
#include "display/IDisplayOutput.h"

class DisplayController
{
    private: 
        IDisplayOutput& displayOutput;

    public:
        DisplayController(IDisplayOutput& displayOutput) : displayOutput(displayOutput) {};
        void updateDisplay(const Measurements& measurements, SystemState systemState);
};