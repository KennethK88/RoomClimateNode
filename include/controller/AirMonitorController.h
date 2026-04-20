#pragma once
#include "sensors/ThermistorDriver.h"
#include "sensors/HumidityDriver.h"
#include "sensors/TemperatureSensor.h"
#include "sensors/HumiditySensor.h"
#include "sensors/SensorCoordinator.h"
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
        TemperatureSensor temperatureSensor;
        HumiditySensor humiditySensor;
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
        AirMonitorController() : temperatureSensor(thermistorDriver), humiditySensor(humidityDriver), sensorCoordinator(temperatureSensor, humiditySensor), displayController(oledDriver), alarmController(compositeAlarmOutput) {}
        void init();
        void update();
};

// TODO: AirMonitorController aufteilen