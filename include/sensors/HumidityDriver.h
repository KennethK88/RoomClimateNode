#pragma once
#include <DHT.h>
#include "utils/HardwareConfig.h"


class HumidityDriver
{
    private:
        DHT dht{HardwareConfig::HUMIDITY_DRIVER_DIGITAL_IN_PIN, HardwareConfig::HUMIDITY_DRIVER_TYPE};

    public:
        HumidityDriver() = default;
        void init();
        float getHumidity();
};