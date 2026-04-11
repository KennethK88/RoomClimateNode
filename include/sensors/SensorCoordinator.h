#pragma once
#include "TemperatureSensor.h"
#include "SimulatedHumiditySensor.h"
#include "COSensor.h"
#include "Measurements.h"

//TODO: Als Interface umsetzen?

class SensorCoordinator
{
    private:
        TemperatureSensor tempSens;
        SimulatedHumiditySensor humSens;
        COSensor coSens;

    public:
        SensorCoordinator() = default;
        Measurements readAllSensors();
};