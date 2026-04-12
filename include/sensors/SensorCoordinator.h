#pragma once
#include "sensors/ISensor.h"
#include <Measurements.h>

class SensorCoordinator
{
    private:
        ISensor& tempSens;
        ISensor& humSens;
        ISensor& coSens;

    public:
        SensorCoordinator(ISensor& tempSens, ISensor& humSens, ISensor& coSens) : tempSens(tempSens), humSens(humSens), coSens(coSens) {}
        Measurements readAllSensors();
};