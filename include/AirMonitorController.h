#pragma once
#include "SensorCoordinator.h"
#include "SensorValidator.h"
#include "ThresholdEvaluator.h"
#include "StateMachine.h"
#include "DisplayController.h"
#include "AlarmController.h"
#include "BuzzerDriver.h"
#include "LedDriver.h"
#include "CompositeAlarmOutput.h"
#include "OledDriver.h"

class AirMonitorController
{
    private:
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
        AirMonitorController() : displayController(oledDriver), alarmController(compositeAlarmOutput) {}
        void init();
        void update();
};