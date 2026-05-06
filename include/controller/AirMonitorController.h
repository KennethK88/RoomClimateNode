#pragma once
#include <ThermistorDriver.h>
#include "sensors/HumidityDriver.h"
#include "sensors/CODriver.h"
#include <DistanceDriver.h>
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

/**
 * @file AirMonitorController.h
 * @class AirMonitorController
 * @brief Zentrale Orchestrierung des Luftüberwachungssystems
 *
 * Der AirMonitorController verbindet Sensoren, Auswertung, Anzeige und Alarmierung
 * zu einem vollständigen Systemablauf.
 *
 * Die Klasse besitzt die konkreten Hardware-Treiber und fachlichen Komponenten
 * und koordiniert deren Zusammenspiel im zyklischen Betrieb.
 *
 * Verantwortlichkeiten:
 * - Initialisierung aller Hardware- und Systemkomponenten
 * - zyklisches Auslesen der Sensoren
 * - Validierung und Bewertung der Messwerte
 * - Berechnung des Systemzustands
 * - Aktualisierung von Display und Alarm
 *
 * @note Die fachliche Logik liegt bewusst in separaten Klassen wie
 * SensorValidator, ThresholdEvaluator, StateMachine und DisplayPolicy.
 * Der AirMonitorController dient primär als Orchestrator.
 */
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

        /**
         * @brief Konstruktor
         *
         * Erstellt und verdrahtet alle benötigten Systemkomponenten.
         */
        AirMonitorController() :    temperatureSensor(thermistorDriver), humiditySensor(humidityDriver), coSensor(coDriver), distanceSensor(distanceDriver),
                                    sensorCoordinator(temperatureSensor, humiditySensor, coSensor, distanceSensor), 
                                    displayController(oledDriver), alarmController(compositeAlarmOutput) {}
        
        /**
         * @brief Initialisiert das Luftüberwachungssystem
         *
         * Initialisiert die angebundenen Hardware-Treiber und bereitet die
         * Systemkomponenten für den zyklischen Betrieb vor.
         */
        void init();

        /**
         * @brief Führt einen vollständigen Aktualisierungszyklus aus
         *
         * Liest alle Sensoren aus, validiert und bewertet die Messwerte,
         * berechnet den aktuellen Systemzustand und aktualisiert Display
         * sowie Alarm.
         */
        void update();
};