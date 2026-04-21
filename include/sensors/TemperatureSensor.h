#pragma once
#include <CommonSensorConstants.h>
#include "sensors/ISensorDriver.h"

class TemperatureSensor
{
    private:
        float currentTemperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
        ISensorDriver& sensorDriver;

    public:
        TemperatureSensor(ISensorDriver& sensorDriver) : sensorDriver(sensorDriver) {}
        void readTemperature();
        float getTemperature() const;
};