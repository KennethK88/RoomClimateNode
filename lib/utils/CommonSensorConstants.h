#pragma once

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
    constexpr float TEMPERATURE_NOT_INITIALIZED = -100.0f;

    /**
     * @brief Minimal gültige Temperatur
     */
    constexpr float TEMPERATURE_MIN_VALID = -20.0f;

    /**
     * @brief Maximal gültige Temperatur
     */
    constexpr float TEMPERATURE_MAX_VALID = 40.0f;

    /**
     * @brief Unterer Schwellenwert für Temperatur
     */
    constexpr float TEMPERATURE_MIN_THRESHOLD = 18.0f;

    /**
     * @brief Oberer Schwellenwert für Temperatur
     */
    constexpr float TEMPERATURE_MAX_THRESHOLD = 25.0f;

    /**
     * @brief Gültiger Dummy-Wert für Tests
     */
    constexpr float TEMPERATURE_DUMMY_VALID = 20.0f;


    /**
     * @brief Feuchtigkeitskonstanten (Einheit: %)
     */

    /**
     * @brief Kennwert für nicht initialisierte Luftfeuchtigkeit
     */
    constexpr float HUMIDITY_NOT_INITIALIZED = -100.0f;

    /**
     * @brief Minimal gültige Luftfeuchtigkeit
     */
    constexpr float HUMIDITY_MIN_VALID = 0.0f;

    /**
     * @brief Maximal gültige Luftfeuchtigkeit
     */
    constexpr float HUMIDITY_MAX_VALID = 100.0f;

    /**
     * @brief Unterer Schwellenwert für Luftfeuchtigkeit
     */
    constexpr float HUMIDITY_MIN_THRESHOLD = 30.0f;

    /**
     * @brief Oberer Schwellenwert für Luftfeuchtigkeit
     */
    constexpr float HUMIDITY_MAX_THRESHOLD = 70.0f;

    /**
     * @brief Gültiger Dummy-Wert für Tests
     */
    constexpr float HUMIDITY_DUMMY_VALID = 35.0f;


    /**
     * @brief CO-Konzentrationskonstanten (Einheit: ppm)
     */

    /**
     * @brief Kennwert für nicht initialisierten CO-Wert
     */
    constexpr float CO_NOT_INITIALIZED = -100.0f;

    /**
     * @brief Minimal gültiger CO-Wert
     */
    constexpr float CO_MIN_VALID = 0.0f;

    /**
     * @brief Maximal gültiger CO-Wert
     */
    constexpr float CO_MAX_VALID = 1000.0f;

    /**
     * @brief Oberer Schwellenwert für CO-Konzentration
     */
    constexpr float CO_MAX_THRESHOLD = 200.0f;

    /**
     * @brief Gültiger Dummy-Wert für Tests
     */
    constexpr float CO_DUMMY_VALID = 50.0f;


    /**
     * @brief Distanzkonstanten (Einheit: cm)
     */

    /**
     * @brief Kennwert für nicht initialisierte Distanz
     */
    constexpr float DISTANCE_NOT_INITIALIZED = -100.0f;

    /**
     * @brief Minimal gültige Distanz
     */
    constexpr float DISTANCE_MIN_VALID = 0.0f;

    /**
     * @brief Maximal gültige Distanz
     */
    constexpr float DISTANCE_MAX_VALID = 500.0f;

    /**
     * @brief Schwellwert zur Aktivierung/Deaktivierung des Displays
     */
    constexpr float DISTANCE_ON_OFF_THRESHOLD = 75.0f;

    /**
     * @brief Gültiger Dummy-Wert für Tests
     */
    constexpr float DISTANCE_DUMMY_VALID = 50.0f;

    /**
     * @brief Spezialwert: Kein Objekt erkannt
     * 
     * Ein Wert von 0 wird als gültiger Messwert interpretiert, der bedeutet,
     * dass sich kein Objekt im Messbereich des Sensors befindet.
     */
    constexpr float DISTANCE_NO_OBJECT_DETECTED = 0.0f;
}