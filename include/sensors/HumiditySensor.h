#pragma once
#include <CommonSensorConstants.h>
#include "sensors/HumidityDriver.h"

class HumiditySensor
{
    private:
        float currentHumidity = SensorConstants::HUMIDITY_NOT_INITIALIZED; // TODO: Anderer Startwert?
        HumidityDriver& humidityDriver;

    public:
        HumiditySensor(HumidityDriver& humidityDriver) : humidityDriver(humidityDriver) {}
        void readHumidity();
        float getHumidity() const;
};