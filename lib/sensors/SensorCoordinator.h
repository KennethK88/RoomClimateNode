#pragma once
#include <TemperatureSensor.h>
#include <HumiditySensor.h>
#include <COSensor.h>
#include <Measurements.h>
#include <DistanceSensor.h>

class SensorCoordinator
{
    private:
        TemperatureSensor& tempSens;
        HumiditySensor& humSens;
        COSensor& coSens;
        DistanceSensor& distanceSens;
        

    public:
        SensorCoordinator(TemperatureSensor& tempSens, HumiditySensor& humSens, COSensor& coSens, DistanceSensor& distanceSens) : tempSens(tempSens), humSens(humSens), coSens(coSens), distanceSens(distanceSens) {}
        Measurements readAllSensors();
};