#pragma once
#include <Types.h>

class IBatteryDriver
{
    public:
        virtual ~IBatteryDriver() = default;
        virtual void init() = 0;
        virtual void readVoltage() = 0;
        virtual BatteryVoltage getVoltage() = 0;
};