#pragma once
#include <Measurements.h>
#include <SystemState.h>
#include <IDisplayOutput.h>

class DisplayController
{
    private: 
        IDisplayOutput& displayOutput;
    

    public:
        DisplayController(IDisplayOutput& displayOutput) : displayOutput(displayOutput) {}
        void updateDisplay(const Measurements& measurements, SystemState systemState, bool displayActive);
};