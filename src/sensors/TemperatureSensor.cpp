#include "sensors/TemperatureSensor.h"

void TemperatureSensor::readTemperature(ThermistorDriver& thermistorDriver)
{
    currentTemperature = thermistorDriver.getTemperature(); // TODO: Interface einziehen
}

float TemperatureSensor::getTemperature() const
{
    return currentTemperature;
}