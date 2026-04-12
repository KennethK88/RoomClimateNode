#pragma once
#include <CommonSensorConstants.h>
#include "sensors/ISensor.h"

class COSensor : public ISensor
{
    private:
        float currentCO = SensorConstants::CO_NOT_INITIALIZED;

    public:
        COSensor() = default;
        void readValue() override;
        float getValue() const override;
};

