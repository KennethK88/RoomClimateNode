#pragma once
#include "sensors/TemperatureSensor.h"
#include "sensors/HumiditySensor.h"
#include "sensors/SimulatedCOSensor.h"
#include "data/Measurements.h"

//TODO: Als Interface umsetzen?

class SensorCoordinator
{
    private:
        TemperatureSensor tempSens;
        HumiditySensor humSens;
        SimulatedCOSensor coSens;

    public:
        SensorCoordinator() = default;
        Measurements readAllSensors();
};