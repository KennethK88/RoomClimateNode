#include <SensorCoordinator.h>

Measurements SensorCoordinator::readAllSensors()
{
    Measurements measurements;
    tempSens.readTemperature();
    humSens.readHumidity();
    measurements.temperature = tempSens.getTemperature();
    measurements.humidity = humSens.getHumidity();
    return measurements;
}