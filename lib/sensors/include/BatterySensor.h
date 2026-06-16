#pragma once
#include <IBatteryDriver.h>

class BatterySensor
{
    private:
        IBatteryDriver& batteryDriver;

    public:
        BatterySensor(IBatteryDriver& batteryDriver) : batteryDriver(batteryDriver) {}
        BatteryLevel getBatteryLevel() const;
};