#pragma once
#include <CommonSensorConstants.h>
#include <ISensorDriver.h>

class HumiditySensor
{
    private:
        float currentHumidity = SensorConstants::HUMIDITY_NOT_INITIALIZED; // TODO: Anderer Startwert?
        ISensorDriver& sensorDriver;

    public:
        HumiditySensor(ISensorDriver& sensorDriver) : sensorDriver(sensorDriver) {}
        void readHumidity();
        float getHumidity() const;
};