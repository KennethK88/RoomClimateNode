#pragma once
#include "Types.h"
#include "CommonSensorConstants.h"
#include <BatteryConstants.h>

/**
 * @file Measurements.h
 * @brief Data structure for current measurement values of the room climate node.
 *
 * This structure combines the currently acquired measurement values into a
 * common data format. It is typically filled by the SensorCoordinator and then
 * processed by validation, state evaluation and publishing components.
 */
struct Measurements
{
    /**
     * @brief Current temperature value in degrees Celsius.
     */
    Temperature temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;

    /**
     * @brief Current temperature value in degrees Celsius.
     */
    Humidity humidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;

    /**
     * @brief Current battery level value in percent.
     *
     * Valid values are in the range from 0 to 100. A special value is used
     * to indicate that no valid battery level is currently available.
     */
    BatteryLevel batteryLevel = BatteryConstants::BATTERY_LEVEL_NOT_INITIALIZED;
};