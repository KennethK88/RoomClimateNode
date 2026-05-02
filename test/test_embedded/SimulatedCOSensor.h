#pragma once
#include <CommonSensorConstants.h>

class SimulatedCOSensor
{
    private:
        float currentCO = 20.0f; // TODO: Anderer Startwert?
        int direction = 1; // NOTE: 1 = hoch; -1 = runter
        float stepsize = 50;

    public:
        SimulatedCOSensor() = default;
        void readCO();
        float getCO() const;
};