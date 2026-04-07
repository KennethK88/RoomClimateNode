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

class AirMonitorController
{
    private:
        SensorCoordinator sensorCoordinator;
        SensorValidator sensorValidator;
        ThresholdEvaluator thresholdEvaluator;
        DisplayController displayController;
        StateMachine stateMachine;
        BuzzerDriver buzzerDriver;
        LedDriver ledDriver;
        CompositeAlarmOutput compositeAlarmOutput;
        AlarmController alarmController;

    public:
        AirMonitorController() : alarmController(compositeAlarmOutput) {}
        void init();
        void update();
};