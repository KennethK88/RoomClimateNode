#pragma once
#include "sensors/TemperatureSensor.h"
#include "sensors/HumiditySensor.h"
#include "sensors/COSensor.h"
#include <Measurements.h>

//TODO: Als Interface umsetzen?

class SensorCoordinator
{
    private:
        TemperatureSensor tempSens;
        HumiditySensor humSens;
        COSensor coSens;

    public:
        SensorCoordinator() = default;
        Measurements readAllSensors();
};