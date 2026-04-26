#pragma once
#include <DHT.h>
#include "utils/HardwareConfig.h"
#include <ISensorDriver.h>


class HumidityDriver : public ISensorDriver
{
    private:
        DHT dht{HardwareConfig::HUMIDITY_DRIVER_PIN, HardwareConfig::HUMIDITY_DRIVER_TYPE};

    public:
        HumidityDriver() = default;
        void init() override;
        float getValue() override;
};