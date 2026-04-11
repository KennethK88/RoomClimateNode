#pragma once
#include "utils/CommonSensorConstants.h"

class SimulatedTemperatureSensor
{
    private:
        float currentTemperature = 20.0f; // TODO: Anderer Startwert?
        int direction = 1; // NOTE: 1 = hoch; -1 = runter
        float stepsize = 0.5f;

    public:
        SimulatedTemperatureSensor() = default;
        void readTemperature();
        float getTemperature() const;
};