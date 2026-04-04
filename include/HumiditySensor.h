#pragma once
#include "CommonSensorConstants.h"

class HumiditySensor
{
    private:
        float currentHumidity=SensorConstants::HUMIDITY_NOT_INITIALIZED; // TODO: Anderer Startwert?

    public:
        HumiditySensor()=default;
        void readHumidity();
        float getHumidity() const;
};

