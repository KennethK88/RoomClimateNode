#pragma once
#include "sensors/ISensor.h"
#include "sensors/TemperatureSensor.h"
#include <Measurements.h>

class SensorCoordinator
{
    private:
        TemperatureSensor tempSens;
        ISensor& humSens;
        ISensor& coSens;

    public:
        SensorCoordinator(TemperatureSensor tempSens, ISensor& humSens, ISensor& coSens) : tempSens(tempSens), humSens(humSens), coSens(coSens) {}
        Measurements readAllSensors();
};