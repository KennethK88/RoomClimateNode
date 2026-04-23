#include <SensorCoordinator.h>

Measurements SensorCoordinator::readAllSensors()
{
    Measurements measurements;
    tempSens.readTemperature();
    humSens.readHumidity();
    coSens.readCO();
    measurements.temperature = tempSens.getTemperature();
    measurements.humidity = humSens.getHumidity();
    measurements.co = coSens.getCO();
    return measurements;
}