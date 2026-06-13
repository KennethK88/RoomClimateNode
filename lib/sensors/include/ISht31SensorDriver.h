#pragma once
#include <Types.h>
#include <cstdint>

class ISht31SensorDriver
{
    public:
        virtual ~ISht31SensorDriver() = default;
        virtual void init() = 0;
        virtual void readMeasurements() = 0;
        virtual Temperature getTemperature() = 0;
        virtual Humidity getHumidity() = 0;
};