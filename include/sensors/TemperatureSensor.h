#pragma once
#include <CommonSensorConstants.h>
#include "sensors/ThermistorDriver.h"

class TemperatureSensor
{
    private:
        float currentTemperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
        ThermistorDriver& thermistorDriver;

    public:
        TemperatureSensor(ThermistorDriver& thermistorDriver) : thermistorDriver(thermistorDriver) {}
        void readTemperature();
        float getTemperature() const;
};