#pragma once
#include <ThermistorDriver.h>
#include <HumidityDriver.h>
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
#include <LedDriver.h>
#include "display/OledDriver.h"
#include <HardwareConfig.h>
#include <LedController.h>

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
 * - Aktualisierung von Display, Alarm und Status-LEDs
 *
 * @note Die fachliche Logik liegt bewusst in separaten Klassen wie
 * SensorValidator, ThresholdEvaluator, StateMachine und DisplayPolicy.
 * Der AirMonitorController dient primär als Orchestrator.
 */
class AirMonitorController
{
    private:
        // Driver
        ThermistorDriver thermistorDriver;
        HumidityDriver humidityDriver;
        CODriver coDriver;
        DistanceDriver distanceDriver;
        BuzzerDriver buzzerDriver;
        LedDriver ledDriverNormal{HardwareConfig::LED_NORMAL_DIGITAL_PIN};
        LedDriver ledDriverWarning{HardwareConfig::LED_WARNING_DIGITAL_PIN};
        LedDriver ledDriverError{HardwareConfig::LED_ERROR_DIGITAL_PIN};
        OledDriver oledDriver;
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
         * Erstellt und verdrahtet alle benötigten Systemkomponenten einschließlich
         * Sensorik, Anzeige, Alarmierung und Status-LEDs.
         */
        AirMonitorController() :    temperatureSensor(thermistorDriver), humiditySensor(humidityDriver), coSensor(coDriver), distanceSensor(distanceDriver),
                                    sensorCoordinator(temperatureSensor, humiditySensor, coSensor, distanceSensor), 
                                    displayController(oledDriver), alarmController(buzzerDriver), ledController(ledDriverNormal, ledDriverWarning, ledDriverError) {}
        
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