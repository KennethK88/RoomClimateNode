#include "sensors/HumidityDriver.h"

void HumidityDriver::init()
{
    dht.begin();
}

float HumidityDriver::getHumidity()
{
    return dht.readHumidity();
}