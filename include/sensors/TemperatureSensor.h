#pragma once
#include "utils/CommonSensorConstants.h"
#include "sensors/ISensor.h"

class TemperatureSensor : public ISensor
{
    private:
        float currentTemperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED; // TODO: Anderer Startwert?

    public:
        TemperatureSensor() = default;
        void readValue() override;
        float getValue() const override;
};