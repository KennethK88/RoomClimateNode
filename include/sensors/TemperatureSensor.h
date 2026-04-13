#pragma once
#include <CommonSensorConstants.h>
#include "sensors/ISensor.h"

class TemperatureSensor : public ISensor
{
    private:
        float currentTemperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;

    public:
        TemperatureSensor() = default;
        void readValue() override;
        float getValue() const override;
};