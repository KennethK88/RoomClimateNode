#pragma once
#include "CommonSensorConstants.h"

class TemperatureSensor
{
    private:
        float currentTemperature=SensorConstants::TEMPERATURE_NOT_INITIALIZED; // TODO: Anderer Startwert?

    public:
        TemperatureSensor() = default;
        void readTemperature();
        float getTemperature() const;
};

