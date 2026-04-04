#pragma once
#include "SensorCoordinator.h"
#include "SensorValidator.h"
#include "ThresholdEvaluator.h"
#include "StateMachine.h"
#include "DisplayController.h"
#include "AlarmController.h"

class AirMonitorController
{
    private:
        SensorCoordinator sensorCoordinator;
        SensorValidator sensorValidator;
        ThresholdEvaluator thresholdEvaluator;
        DisplayController displayController;
        StateMachine stateMachine;
        AlarmController alarmController;

    public:
        AirMonitorController() = default;
        void update();
};