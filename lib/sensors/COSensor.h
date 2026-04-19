#pragma once
#include <CommonSensorConstants.h>

class COSensor
{
    private:
        float currentCO = SensorConstants::CO_NOT_INITIALIZED; // TODO: Anderer Startwert?

    public:
        COSensor() = default;
        void readCO();
        float getCO() const;
};