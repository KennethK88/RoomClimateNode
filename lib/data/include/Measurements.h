#pragma once

#include "Types.h"
#include "CommonSensorConstants.h"

#include <BatteryConstants.h>

/**
 * @file Measurements.h
 * @brief Defines the measurement data structure used by the RoomClimateNode.
 */

/**
 * @brief Contains the current temperature, humidity, and battery level measurements.
 *
 * Groups sensor measurements into a common data structure.
 * The values are collected by the SensorCoordinator and subsequently
 * used for validation and MQTT publishing.
 *
 * All members are initialized with their corresponding
 * not-initialized values.
 */
struct Measurements
{
    /**
     * @brief Current temperature in degrees Celsius.
     */
    Temperature temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;

    /**
     * @brief Current relative humidity in percent.
     */
    Humidity humidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;

    /**
     * @brief Current battery level in percent.
     *
     * Valid battery levels range from 0 to 100.
     * BatteryConstants::BATTERY_LEVEL_NOT_INITIALIZED indicates
     * that no battery level has been determined.
     */
    BatteryLevel batteryLevel = BatteryConstants::BATTERY_LEVEL_NOT_INITIALIZED;
};