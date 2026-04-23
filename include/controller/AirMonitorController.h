#pragma once
#include "sensors/ThermistorDriver.h"
#include "sensors/HumidityDriver.h"
#include "sensors/CODriver.h"
#include <TemperatureSensor.h>
#include <HumiditySensor.h>
#include <COSensor.h>
#include <SensorCoordinator.h>
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
        AirMonitorController() : temperatureSensor(thermistorDriver), humiditySensor(humidityDriver), coSensor(coDriver), sensorCoordinator(temperatureSensor, humiditySensor, coSensor), displayController(oledDriver), alarmController(compositeAlarmOutput) {}
        void init();
        void update();
};

// TODO: AirMonitorController aufteilen