#pragma once
#include "sensors/TemperatureSensor.h"
#include "sensors/SimulatedHumiditySensor.h"
#include "sensors/COSensor.h"
#include "data/Measurements.h"

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