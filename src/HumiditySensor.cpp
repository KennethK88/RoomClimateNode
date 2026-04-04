#include "HumiditySensor.h"

void HumiditySensor::readHumidity()
{
    currentHumidity = 20.0f; // TODO: Dummywert ersetzen
}

float HumiditySensor::getHumidity() const
{
    return currentHumidity;
}