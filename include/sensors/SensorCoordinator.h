#pragma once
#include "sensors/TemperatureSensor.h"
#include "sensors/HumiditySensor.h"
#include "sensors/COSensor.h"
#include <Measurements.h>

class SensorCoordinator
{
    private:
        TemperatureSensor& tempSens;
        HumiditySensor& humSens;
        COSensor coSens;

    public:
        SensorCoordinator(TemperatureSensor& tempSens, HumiditySensor& humSens) : tempSens(tempSens), humSens(humSens) {}
        Measurements readAllSensors();
};