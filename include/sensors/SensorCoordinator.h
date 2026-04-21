#pragma once
#include "sensors/TemperatureSensor.h"
#include "sensors/HumiditySensor.h"
#include <COSensor.h>
#include <Measurements.h>

class SensorCoordinator
{
    private:
        TemperatureSensor& tempSens;
        HumiditySensor& humSens;
        COSensor& coSens;

    public:
        SensorCoordinator(TemperatureSensor& tempSens, HumiditySensor& humSens, COSensor& coSens) : tempSens(tempSens), humSens(humSens), coSens(coSens) {}
        Measurements readAllSensors();
};