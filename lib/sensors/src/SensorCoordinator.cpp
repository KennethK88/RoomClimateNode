#include "SensorCoordinator.h"

Measurements SensorCoordinator::readAllSensors()
{
    Measurements measurements;
    measurements.temperature = tempSens.getTemperature();
    measurements.humidity = humSens.getHumidity();
    measurements.batteryLevel = battSens.getBatteryLevel();
    return measurements;
}