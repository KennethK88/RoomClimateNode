#pragma once

/**
 * @file ValidationResults.h
 * @brief Defines the validation results for sensor measurements.
 */

/**
 * @brief Contains individual validation flags for sensor measurements.
 *
 * Provides validation results for temperature, relative humidity,
 * and battery level measurements.
 *
 * Each flag indicates whether the corresponding measurement is valid.
 * All flags are initialized to false by default.
 */
struct ValidationResults
{
    /**
     * @brief Indicates whether the temperature measurement is valid.
     */
    bool temperatureValid = false;

    /**
     * @brief Indicates whether the relative humidity measurement is valid.
     */
    bool humidityValid = false;

    /**
     * @brief Indicates whether the battery level measurement is valid.
     */
    bool batteryLevelValid = false;
};