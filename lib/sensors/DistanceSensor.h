#pragma once
#include <CommonSensorConstants.h>
#include <ISensorDriver.h>

class DistanceSensor
{
    private:
        float currentDistance = SensorConstants::DISTANCE_NOT_INITIALIZED;
        ISensorDriver& sensorDriver;

    public:
        DistanceSensor(ISensorDriver& sensorDriver) : sensorDriver(sensorDriver) {}
        void readDistance();
        float getDistance() const;
};