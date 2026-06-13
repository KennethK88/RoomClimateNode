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
 * @brief Zentrale Orchestrierung des Raumklima-Knotens.
 */

/**
 * @class AirMonitorController
 * @brief Koordiniert Initialisierung, Messwerterfassung, Validierung und Veröffentlichung.
 *
 * Der AirMonitorController bildet den zentralen Ablauf des Raumklima-Knotens ab.
 * Er verbindet die fachlichen Komponenten zur Messwerterfassung und
 * Messwertvalidierung mit abstrahierten Verbindungs- und Ausgabeschnittstellen.
 *
 * Verantwortlichkeiten:
 * - Initialisierung der Sensor-, WLAN- und MQTT-Komponenten
 * - Auslösen der Sensormessung
 * - Erfassen von Temperatur- und Luftfeuchtigkeitswerten
 * - Validierung der Messwerte
 * - Berechnung des aktuellen Systemzustands
 * - Veröffentlichung der Messwerte über eine abstrahierte Publisher-Schnittstelle
 *
 * @note Die Klasse kennt keine konkreten WLAN-, MQTT- oder Sensortreiber.
 * Konkrete Implementierungen werden über Interfaces injiziert, um die fachliche
 * Logik testbar und weitgehend plattformunabhängig zu halten.
 *
 * @note Der Klassenname ist historisch gewachsen. Fachlich beschreibt die Klasse
 * aktuell den zentralen Controller eines Raumklima-Knotens.
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
         * @brief Erstellt den Controller und verdrahtet die benötigten Komponenten.
         *
         * Der Konstruktor erhält die hardwarenahen und kommunikationsbezogenen
         * Abhängigkeiten über Interfaces. Daraus werden die fachlichen Sensorobjekte
         * und der SensorCoordinator aufgebaut.
         *
         * @param sht31SensorDriver Treiberschnittstelle für den SHT31-Sensor.
         * @param wifiConnectionManager Verbindungsmanager für die WLAN-Verbindung.
         * @param mqttClientService Verbindungsmanager für die MQTT-Verbindung.
         * @param measurementPublisher Publisher zur Veröffentlichung der Messwerte.
         */
        AirMonitorController(ISht31SensorDriver& sht31SensorDriver, IConnectionManager& wifiConnectionManager, IConnectionManager& mqttClientService, IMeasurementPublisher& measurementPublisher) : sht31SensorDriver(sht31SensorDriver), wifiConnectionManager(wifiConnectionManager), mqttClientService(mqttClientService), measurementPublisher(measurementPublisher), temperatureSensor(sht31SensorDriver), humiditySensor(sht31SensorDriver), sensorCoordinator(temperatureSensor, humiditySensor) {}

        /**
         * @brief Initialisiert den Raumklima-Knoten.
         *
         * Initialisiert die Verbindungs- und Sensorkomponenten und bereitet das
         * System für den zyklischen Betrieb vor.
         */
        void init();

        /**
         * @brief Führt einen Mess- und Veröffentlichungszyklus aus.
         *
         * Löst eine Sensormessung aus, liest die aktuellen Messwerte ein,
         * validiert die Messwerte, berechnet den Systemzustand und stößt die
         * Veröffentlichung der Messwerte an.
         */
        void update();
};