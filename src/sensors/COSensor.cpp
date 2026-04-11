#include "COSensor.h"

void COSensor::readCO()
{
    currentCO = 20.0f; // FIXME: Dummywert ersetzen
}


float COSensor::getCO() const
{
    return currentCO;
}