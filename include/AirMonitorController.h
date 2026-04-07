#pragma once
#include "SensorCoordinator.h"
#include "SensorValidator.h"
#include "ThresholdEvaluator.h"
#include "StateMachine.h"
#include "DisplayController.h"
#include "AlarmController.h"
#include "BuzzerDriver.h"

class AirMonitorController
{
    private:
        SensorCoordinator sensorCoordinator;
        SensorValidator sensorValidator;
        ThresholdEvaluator thresholdEvaluator;
        DisplayController displayController;
        StateMachine stateMachine;
        BuzzerDriver buzzerDriver;
        AlarmController alarmController;

    public:
        AirMonitorController() : alarmController(buzzerDriver) {}
        void init();
        void update();
};