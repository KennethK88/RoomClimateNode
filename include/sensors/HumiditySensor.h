#pragma once
#include "utils/CommonSensorConstants.h"
#include "sensors/ISensor.h"

class HumiditySensor : public ISensor
{
    private:
        float currentHumidity=SensorConstants::HUMIDITY_NOT_INITIALIZED; // TODO: Anderer Startwert?

    public:
        HumiditySensor() = default;
        void readValue() override;
        float getValue() const override;
};