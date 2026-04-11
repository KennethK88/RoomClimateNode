#include "sensors/HumiditySensor.h"

void HumiditySensor::readValue()
{
    currentHumidity = 35.0f; // TODO: Dummywert ersetzen
}

float HumiditySensor::getValue() const
{
    return currentHumidity;
}