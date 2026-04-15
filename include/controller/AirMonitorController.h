#pragma once
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

// TODO: AirMonitorController aufteilen