#include "sensors/HumiditySensor.h"

void HumiditySensor::readHumidity()
{
    currentHumidity = humidityDriver.getHumidity();
}

float HumiditySensor::getHumidity() const
{
    return currentHumidity;
}