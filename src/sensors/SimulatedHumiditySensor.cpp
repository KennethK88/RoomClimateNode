#include "sensors/SimulatedHumiditySensor.h"

void SimulatedHumiditySensor::readHumidity()
{
        if(currentHumidity >= 101.0f)
    {
        currentHumidity= 101.0f;
        direction = -1;
    }
    else if(currentHumidity <= -1.0f)
    {
        currentHumidity = -1.0f;
        direction = 1;
    }
    currentHumidity += direction * stepsize;
}

float SimulatedHumiditySensor::getHumidity() const
{
    return currentHumidity;
}