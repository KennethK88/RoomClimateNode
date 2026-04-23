#include <TemperatureSensor.h>

void TemperatureSensor::readTemperature()
{
    currentTemperature = sensorDriver.getValue();
}

float TemperatureSensor::getTemperature() const
{
    return currentTemperature;
}