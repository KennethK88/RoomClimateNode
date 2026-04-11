#include "sensors/TemperatureSensor.h"

void TemperatureSensor::readTemperature()
{
    currentTemperature = 20.0f; // TODO: Dummywert ersetzen
}

float TemperatureSensor::getTemperature() const
{
    return currentTemperature;
}