#pragma once
#include <Types.h>
#include <CommonSensorConstants.h>

/**
 * @file Measurements.h
 * @brief Datenstruktur für aktuelle Messwerte des Raumklima-Knotens.
 *
 * Diese Struktur fasst die erfassten Messwerte in einem gemeinsamen
 * Austauschformat zusammen. Sie wird typischerweise vom SensorCoordinator
 * befüllt und anschließend von Validierung, Zustandslogik und Publishern
 * weiterverarbeitet.
 */
struct Measurements
{
    /**
     * @brief Aktueller Temperaturwert in °C.
     */
    Temperature temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;

    /**
     * @brief Aktueller Wert der relativen Luftfeuchtigkeit in %.
     */
    Humidity humidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;
};