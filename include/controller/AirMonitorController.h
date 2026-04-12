#pragma once
#include "sensors/SensorCoordinator.h"
#include "evaluation/SensorValidator.h"
#include "evaluation/ThresholdEvaluator.h"
#include "evaluation/StateMachine.h"
#include "display/DisplayController.h"
#include "alarm/AlarmController.h"
#include "alarm/BuzzerDriver.h"
#include "alarm/LedDriver.h"
#include "alarm/CompositeAlarmOutput.h"
#include "display/OledDriver.h"
#include "sensors/TemperatureSensor.h"
#include "sensors/HumiditySensor.h"
#include "sensors/COSensor.h"

class AirMonitorController
{
    private:
        TemperatureSensor temperatureSensor;
        HumiditySensor humiditySensor;
        COSensor coSensor;
        SensorCoordinator sensorCoordinator;
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
        AirMonitorController() : sensorCoordinator(temperatureSensor, humiditySensor, coSensor), displayController(oledDriver), alarmController(compositeAlarmOutput) {}
        void init();
        void update();
};

// TODO: AirMonitorController aufteilen