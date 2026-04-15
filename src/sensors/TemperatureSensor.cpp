#include "sensors/TemperatureSensor.h"

void TemperatureSensor::readTemperature()
{
    currentTemperature = thermistorDriver.getTemperature();
}

float TemperatureSensor::getTemperature() const
{
    return currentTemperature;
}