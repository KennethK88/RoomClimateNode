#pragma once
#include "sensors/ThermistorDriver.h"
#include "sensors/HumidityDriver.h"
#include "sensors/CODriver.h"
#include "sensors/DistanceDriver.h"
#include <TemperatureSensor.h>
#include <HumiditySensor.h>
#include <COSensor.h>
#include <DistanceSensor.h>
#include <SensorCoordinator.h>
#include <DisplayPolicy.h>
#include <SensorValidator.h>
#include <ThresholdEvaluator.h>
#include <StateMachine.h>
#include <DisplayController.h>
#include <AlarmController.h>
#include "alarm/BuzzerDriver.h"
#include "alarm/LedDriver.h"
#include "alarm/CompositeAlarmOutput.h"
#include "display/OledDriver.h"

class AirMonitorController
{
    private:
        ThermistorDriver thermistorDriver;
        HumidityDriver humidityDriver;
        CODriver coDriver;
        DistanceDriver distanceDriver;
        TemperatureSensor temperatureSensor;
        HumiditySensor humiditySensor;
        COSensor coSensor;
        DistanceSensor distanceSensor;
        SensorCoordinator sensorCoordinator;
        DisplayPolicy displayPolicy;
        SensorValidator sensorValidator;
        ThresholdEvaluator thresholdEvaluator;
        OledDriver oledDriver;
        DisplayController displayController;
        StateMachine stateMachine;
        BuzzerDriver buzzerDriver;
        LedDriver ledDriver;
        CompositeAlarmOutput compositeAlarmOutput;
        AlarmController alarmController;

    public:
        AirMonitorController() :    temperatureSensor(thermistorDriver), humiditySensor(humidityDriver), coSensor(coDriver), distanceSensor(distanceDriver),
                                    sensorCoordinator(temperatureSensor, humiditySensor, coSensor, distanceSensor), 
                                    displayController(oledDriver), alarmController(compositeAlarmOutput) {}
        void init();
        void update();
};

// TODO: AirMonitorController aufteilen