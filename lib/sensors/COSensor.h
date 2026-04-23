#pragma once
#include <CommonSensorConstants.h>
#include <ISensorDriver.h>

class COSensor
{
    private:
        float currentCO = SensorConstants::CO_NOT_INITIALIZED; // TODO: Anderer Startwert?
        ISensorDriver& sensorDriver;

    public:
        COSensor(ISensorDriver& sensorDriver) : sensorDriver(sensorDriver) {}
        void readCO();
        float getCO() const;
};