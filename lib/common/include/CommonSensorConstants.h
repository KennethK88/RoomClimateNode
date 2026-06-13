#pragma once
#include <Types.h>

/**
 * @file CommonSensorConstants.h
 * @brief Zentrale Definition sensorbezogener Konstanten.
 *
 * Dieses Namespace enthält gemeinsame Konstanten für die Verarbeitung und
 * Validierung von Sensormesswerten des Raumklima-Knotens.
 *
 * Dazu gehören:
 * - Kennwerte für nicht initialisierte Messwerte
 * - gültige Wertebereiche
 * - Fehlerwerte für fehlgeschlagene Messungen
 * - Dummy-Werte für Tests
 *
 * Die Konstanten dienen dazu, sensorbezogene Grenz- und Sonderwerte zentral
 * zu verwalten und in Produktion und Tests konsistent zu verwenden.
 */
namespace SensorConstants
{

    /**
     * @brief Kennwert für eine nicht initialisierte Temperatur.
     */
    constexpr Temperature TEMPERATURE_NOT_INITIALIZED = -100.0f;

    /**
     * @brief Minimal gültige Temperatur in °C.
     */
    constexpr Temperature TEMPERATURE_MIN_VALID = -20.0f;

    /**
     * @brief Maximal gültige Temperatur in °C.
     */
    constexpr Temperature TEMPERATURE_MAX_VALID = 40.0f;

    /**
     * @brief Gültiger Temperatur-Dummywert für Tests in °C.
     */
    constexpr Temperature TEMPERATURE_DUMMY_VALID = 20.0f;

    /**
     * @brief Fehlerwert für eine fehlgeschlagene Temperaturmessung.
     */
    constexpr Temperature TEMPERATURE_MEASUREMENT_ERROR = -999.0f;

    /**
     * @brief Kennwert für eine nicht initialisierte Luftfeuchtigkeit.
     */
    constexpr Humidity HUMIDITY_NOT_INITIALIZED = -100.0f;

    /**
     * @brief Minimal gültige Luftfeuchtigkeit in %.
     */
    constexpr Humidity HUMIDITY_MIN_VALID = 0.0f;

    /**
     * @brief Maximal gültige Luftfeuchtigkeit in %.
     */
    constexpr Humidity HUMIDITY_MAX_VALID = 100.0f;

    /**
     * @brief Gültiger Luftfeuchtigkeits-Dummywert für Tests in %.
     */
    constexpr Humidity HUMIDITY_DUMMY_VALID = 35.0f;
    
    /**
     * @brief Fehlerwert für eine fehlgeschlagene Luftfeuchtigkeitsmessung.
     */
    constexpr Humidity HUMIDITY_MEASUREMENT_ERROR = -999.0f;
}