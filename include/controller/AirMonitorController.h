#pragma once
#include "sensors/ThermistorDriver.h"
#include "sensors/TemperatureSensor.h"
#include "sensors/SensorCoordinator.h"
#include <SensorValidator.h>
#include <ThresholdEvaluator.h>
#include "evaluation/StateMachine.h"
#include "display/DisplayController.h"
#include "alarm/AlarmController.h"
#include "alarm/BuzzerDriver.h"
#include "alarm/LedDriver.h"
#include "alarm/CompositeAlarmOutput.h"
#include "display/OledDriver.h"

class AirMonitorController
{
    private:
        ThermistorDriver thermistorDriver;
        TemperatureSensor temperatureSensor;
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
        AirMonitorController() : temperatureSensor(thermistorDriver), sensorCoordinator(temperatureSensor), displayController(oledDriver), alarmController(compositeAlarmOutput) {}
        void init();
        void update();
};

// TODO: AirMonitorController aufteilen