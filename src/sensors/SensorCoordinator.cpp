#include "sensors/SensorCoordinator.h"

Measurements SensorCoordinator::readAllSensors()
{
    Measurements measurements;
    tempSens.readTemperature();
    humSens.readValue();
    coSens.readValue();
    measurements.temperature = tempSens.getTemperature();
    measurements.humidity = humSens.getValue();
    measurements.co = coSens.getValue();
    return measurements;
}