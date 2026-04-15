#include "sensors/HumiditySensor.h"

void HumiditySensor::readHumidity()
{
    currentHumidity = 35.0f; // TODO: Dummywert ersetzen
}

float HumiditySensor::getHumidity() const
{
    return currentHumidity;
}