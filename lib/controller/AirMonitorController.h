#pragma once
#include <ISensorDriver.h>
#include <IAlarmOutput.h>
#include <ILedOutput.h>
#include <IDisplayOutput.h>
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
#include <LedController.h>

/**
 * @file AirMonitorController.h
 * @class AirMonitorController
 * @brief Zentrale Orchestrierung des Luftüberwachungssystems
 *
 * Der AirMonitorController verbindet Sensorik, Auswertung, Anzeige und
 * Alarmierung zu einem vollständigen Systemablauf.
 *
 * Die Klasse koordiniert fachliche Komponenten sowie abstrahierte
 * Hardware-Schnittstellen und führt den zyklischen Systemablauf aus.
 *
 * Verantwortlichkeiten:
 * - Initialisierung aller Hardware- und Systemkomponenten
 * - zyklisches Auslesen der Sensoren
 * - Validierung und Bewertung der Messwerte
 * - Berechnung des Systemzustands
 * - Aktualisierung von Display, Alarm und Status-LEDs
 *
 * @note Die fachliche Logik liegt bewusst in separaten Klassen wie
 * SensorValidator, ThresholdEvaluator, StateMachine und DisplayPolicy.
 * Der AirMonitorController dient primär als Orchestrator.
 *
 * @note Konkrete Hardwareimplementierungen werden bewusst über Interfaces
 * injiziert, um Testbarkeit und Plattformunabhängigkeit zu ermöglichen.
 */
class AirMonitorController
{
    private:
        // Interfaces
        ISensorDriver& sensorDriverThermistor;
        ISensorDriver& sensorDriverHumidity;
        ISensorDriver& sensorDriverCo;
        ISensorDriver& sensorDriverDistance;
        IAlarmOutput& alarmOutput;
        ILedOutput& ledOutputNormal;
        ILedOutput& ledOutputWarning;
        ILedOutput& ledOutputError;
        IDisplayOutput& displayOutput;
        // Sensoren
        TemperatureSensor temperatureSensor;
        HumiditySensor humiditySensor;
        COSensor coSensor;
        DistanceSensor distanceSensor;
        // Logik
        SensorCoordinator sensorCoordinator;
        DisplayPolicy displayPolicy;
        SensorValidator sensorValidator;
        ThresholdEvaluator thresholdEvaluator;
        DisplayController displayController;
        StateMachine stateMachine;
        AlarmController alarmController;
        LedController ledController;

    public:

        /**
         * @brief Konstruktor
         *
         * Erstellt und verdrahtet alle benötigten Systemkomponenten unter
         * Verwendung abstrahierter Hardware-Schnittstellen.
         *
         * Die konkreten Hardwareimplementierungen werden über Interfaces
         * injiziert, um eine hardwareunabhängige und testbare Architektur
         * zu ermöglichen.
         */
        AirMonitorController(ISensorDriver& sensorDriverThermistor, ISensorDriver& sensorDriverHumidity, ISensorDriver& sensorDriverCo, ISensorDriver& sensorDriverDistance, IAlarmOutput& alarmOutput, ILedOutput& ledOutputNormal, ILedOutput& ledOutputWarning, ILedOutput& ledOutputError, IDisplayOutput& displayOutput) : sensorDriverThermistor(sensorDriverThermistor), sensorDriverHumidity(sensorDriverHumidity), sensorDriverCo(sensorDriverCo), sensorDriverDistance(sensorDriverDistance), alarmOutput(alarmOutput), ledOutputNormal(ledOutputNormal), ledOutputWarning(ledOutputWarning), ledOutputError(ledOutputError), displayOutput(displayOutput), temperatureSensor(sensorDriverThermistor), humiditySensor(sensorDriverHumidity), coSensor(sensorDriverCo), distanceSensor(sensorDriverDistance), 
        sensorCoordinator(temperatureSensor, humiditySensor, coSensor, distanceSensor), displayController(displayOutput), alarmController(alarmOutput), 
        ledController(ledOutputNormal, ledOutputWarning, ledOutputError) {}
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
         * berechnet den aktuellen Systemzustand und aktualisiert Display,
         * Alarm sowie Status-LEDs.
         */
        void update();
};