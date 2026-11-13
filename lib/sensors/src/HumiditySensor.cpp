#include "HumiditySensor.h"

Humidity HumiditySensor::getHumidity() const
{
    return sht31SensorDriver.getHumidity();
}