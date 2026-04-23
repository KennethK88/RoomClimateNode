#include <COSensor.h>

void COSensor::readCO()
{
    currentCO = sensorDriver.getValue(); // FIXME: Dummywert ersetzen
}

float COSensor::getCO() const
{
    return currentCO;
}