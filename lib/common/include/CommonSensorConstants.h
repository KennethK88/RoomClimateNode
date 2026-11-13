#pragma once

#include "Types.h"

/**
 * @file CommonSensorConstants.h
 * @brief Defines common constants for sensor measurement processing and validation.
 */

/**
 * @brief Contains constants for temperature and humidity measurements.
 *
 * Defines application-specific validation limits, initialization values,
 * measurement error indicators, and valid test values.
 *
 * These constants ensure consistent handling of sensor measurements
 * throughout the RoomClimateNode.
 */
namespace SensorConstants
{
    /**
     * @brief Value indicating an uninitialized temperature measurement.
     */
    constexpr Temperature TEMPERATURE_NOT_INITIALIZED = -100.0f;

    /**
     * @brief Minimum valid temperature in degrees Celsius.
     */
    constexpr Temperature TEMPERATURE_MIN_VALID = -20.0f;

    /**
     * @brief Maximum valid temperature in degrees Celsius.
     */
    constexpr Temperature TEMPERATURE_MAX_VALID = 40.0f;

    /**
     * @brief Valid dummy temperature value used for testing.
     */
    constexpr Temperature TEMPERATURE_DUMMY_VALID = 20.0f;

    /**
     * @brief Error value indicating a failed temperature measurement.
     */
    constexpr Temperature TEMPERATURE_MEASUREMENT_ERROR = -999.0f;

    /**
     * @brief Value indicating an uninitialized humidity measurement.
     */
    constexpr Humidity HUMIDITY_NOT_INITIALIZED = -100.0f;

    /**
     * @brief Minimum valid relative humidity in percent.
     */
    constexpr Humidity HUMIDITY_MIN_VALID = 0.0f;

    /**
     * @brief Maximum valid relative humidity in percent.
     */
    constexpr Humidity HUMIDITY_MAX_VALID = 100.0f;

    /**
     * @brief Valid dummy humidity value used for testing.
     */
    constexpr Humidity HUMIDITY_DUMMY_VALID = 35.0f;

    /**
     * @brief Error value indicating a failed humidity measurement.
     */
    constexpr Humidity HUMIDITY_MEASUREMENT_ERROR = -999.0f;
}