#include "sensors/HumidityDriver.h"

void HumidityDriver::init()
{
    dht.begin();
}

float HumidityDriver::getValue()
{
    return dht.readHumidity();
}