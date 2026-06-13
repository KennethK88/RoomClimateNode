#pragma once
#include <ISht31SensorDriver.h>
#include <IConnectionManager.h>
#include <IMeasurementPublisher.h>
#include <TemperatureSensor.h>
#include <HumiditySensor.h>
#include <SensorCoordinator.h>
#include <SensorValidator.h>
#include <StateMachine.h>

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
        ISht31SensorDriver& sht31SensorDriver;
        IConnectionManager& wifiConnectionManager;
        IConnectionManager& mqttClientService;
        IMeasurementPublisher& measurementPublisher;

        // Sensors
        TemperatureSensor temperatureSensor;
        HumiditySensor humiditySensor;
        SensorCoordinator sensorCoordinator;

        // Evaluation
        SensorValidator sensorValidator;
        StateMachine stateMachine;

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
        AirMonitorController(ISht31SensorDriver& sht31SensorDriver, IConnectionManager& wifiConnectionManager, IConnectionManager& mqttClientService, IMeasurementPublisher& measurementPublisher) : sht31SensorDriver(sht31SensorDriver), wifiConnectionManager(wifiConnectionManager), mqttClientService(mqttClientService), measurementPublisher(measurementPublisher), temperatureSensor(sht31SensorDriver), humiditySensor(sht31SensorDriver), sensorCoordinator(temperatureSensor, humiditySensor) {}
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