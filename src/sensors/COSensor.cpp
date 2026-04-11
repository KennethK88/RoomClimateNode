#include "sensors/COSensor.h"

void COSensor::readValue()
{
    currentCO = 20.0f; // TODO: Dummywert ersetzen
}


float COSensor::getValue() const
{
    return currentCO;
}