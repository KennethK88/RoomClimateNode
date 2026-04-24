#include <DistanceSensor.h>

void DistanceSensor::readDistance()
{
    currentDistance = sensorDriver.getValue();
}

float DistanceSensor::getDistance() const
{
    return currentDistance;
}