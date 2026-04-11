#pragma once
#include "utils/CommonSensorConstants.h"

struct Measurements
{
    float temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
    float humidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;
    float co = SensorConstants::CO_NOT_INITIALIZED;
};