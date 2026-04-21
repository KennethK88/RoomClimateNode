#include "sensors/HumiditySensor.h"

void HumiditySensor::readHumidity()
{
    currentHumidity = sensorDriver.getValue();
}

float HumiditySensor::getHumidity() const
{
    return currentHumidity;
}