#include "sensors/SensorCoordinator.h"

Measurements SensorCoordinator::readAllSensors()
{
    Measurements measurements;
    tempSens.readValue();
    humSens.readValue();
    coSens.readValue();
    measurements.temperature = tempSens.getValue();
    measurements.humidity = humSens.getValue();
    measurements.co = coSens.getValue();
    return measurements;
}