#include <TemperatureSensor.h>

Temperature TemperatureSensor::getTemperature() const
{
    return sht31SensorDriver.getTemperature();
}