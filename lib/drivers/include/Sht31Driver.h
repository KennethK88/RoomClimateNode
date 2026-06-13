#pragma once
#include <ISht31SensorDriver.h>
#include <Types.h>
#include <cstdint>
#include <CommonSensorConstants.h>

class Sht31Driver : public ISht31SensorDriver
{
    private:
        uint8_t data[6] = {0};
        Temperature temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
        Humidity humidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;
        
    public:
        Sht31Driver() = default;
        void init() override;
        void readMeasurements() override;
        Temperature getTemperature() override;
        Humidity getHumidity() override;
};