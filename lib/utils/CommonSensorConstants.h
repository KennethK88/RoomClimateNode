#pragma once
#include <Types.h>

/**
 * @file CommonSensorConstants.h
 * @brief Zentrale Definition von Sensorgrenzwerten und Konstanten
 * 
 * Dieses Namespace enthält alle relevanten Konstanten zur Bewertung von
 * Sensormesswerten, einschließlich:
 * - Initialisierungswerte
 * - gültige Wertebereiche
 * - Schwellenwerte für Grenzwertverletzungen
 * - Dummy-Werte für Tests
 * 
 * Ziel ist eine zentrale und konsistente Definition aller sensorbezogenen
 * Parameter zur einfachen Wartbarkeit und Anpassbarkeit.
 */
namespace SensorConstants
{
    /**
     * @brief Temperaturkonstanten (Einheit: °C)
     */
    
    /**
     * @brief Kennwert für nicht initialisierte Temperatur
     */
    constexpr Temperature TEMPERATURE_NOT_INITIALIZED = -100.0f;

    /**
     * @brief Minimal gültige Temperatur
     */
    constexpr Temperature TEMPERATURE_MIN_VALID = -20.0f;

    /**
     * @brief Maximal gültige Temperatur
     */
    constexpr Temperature TEMPERATURE_MAX_VALID = 40.0f;

    /**
     * @brief Gültiger Dummy-Wert für Tests
     */
    constexpr Temperature TEMPERATURE_DUMMY_VALID = 20.0f;

    constexpr Temperature TEMPERATURE_MEASUREMENT_ERROR = -999.0f;


    /**
     * @brief Feuchtigkeitskonstanten (Einheit: %)
     */

    /**
     * @brief Kennwert für nicht initialisierte Luftfeuchtigkeit
     */
    constexpr Humidity HUMIDITY_NOT_INITIALIZED = -100.0f;

    /**
     * @brief Minimal gültige Luftfeuchtigkeit
     */
    constexpr Humidity HUMIDITY_MIN_VALID = 0.0f;

    /**
     * @brief Maximal gültige Luftfeuchtigkeit
     */
    constexpr Humidity HUMIDITY_MAX_VALID = 100.0f;

    /**
     * @brief Gültiger Dummy-Wert für Tests
     */
    constexpr Humidity HUMIDITY_DUMMY_VALID = 35.0f;

    constexpr Humidity HUMIDITY_MEASUREMENT_ERROR = -999.0f;
}