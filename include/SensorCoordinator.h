#pragma once
#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include "COSensor.h"
#include "Measurements.h"

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