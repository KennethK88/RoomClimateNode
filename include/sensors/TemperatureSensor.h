#pragma once
#include <CommonSensorConstants.h>
#include "sensors/ThermistorDriver.h"

class TemperatureSensor
{
    private:
        float currentTemperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;

    public:
        TemperatureSensor() = default;
        void readTemperature(ThermistorDriver& thermistorDriver);
        float getTemperature() const;
};