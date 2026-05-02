#pragma once
#include <CommonSensorConstants.h>

/**
 * @file Measurements.h
 * @brief Struktur zur Speicherung aktueller Sensormesswerte
 * 
 * Diese Struktur fasst die Messwerte aller Sensoren in einer gemeinsamen
 * Datenstruktur zusammen und dient als zentrales Austauschformat zwischen
 * den Systemkomponenten.
 * 
 * Die Werte werden typischerweise durch den SensorCoordinator befüllt und
 * anschließend von Validator, ThresholdEvaluator, StateMachine und weiteren
 * Komponenten weiterverarbeitet.
 */
struct Measurements
{
    /**
     * @brief Aktueller Temperaturwert (Einheit: °C)
     */
    float temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;

    /**
     * @brief Aktueller Feuchtigkeitswert (Einheit: %)
     */
    float humidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;

    /**
     * @brief Aktueller CO-Wert (Einheit: ppm)
     */
    float co = SensorConstants::CO_NOT_INITIALIZED;

    /**
     * @brief Aktueller Distanzwert (Einheit: cm)
     * 
     * @note Ein Wert von 0 bedeutet, dass kein Objekt erkannt wurde
     */
    float distance = SensorConstants::DISTANCE_NOT_INITIALIZED;
};