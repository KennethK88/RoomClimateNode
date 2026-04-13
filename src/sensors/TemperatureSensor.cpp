#include "sensors/TemperatureSensor.h"

void TemperatureSensor::readValue()
{
    currentTemperature = 20.0f; // TODO: Dummywert ersetzen
}

float TemperatureSensor::getValue() const
{
    return currentTemperature;
}