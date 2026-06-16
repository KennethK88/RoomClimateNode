#pragma once
#include <Types.h>

/**
 * @brief Battery-related constants used for voltage and battery level processing.
 *
 * The voltage limits define the mapping range for converting a measured
 * battery voltage into a battery level percentage. Special values are used
 * to represent invalid or uninitialized measurement states.
 */
namespace BatteryConstants
{
    /// Battery voltage representing an empty battery in the linear level mapping.
    constexpr BatteryVoltage BATTERY_VOLTAGE_EMPTY = 3.0f;

     /// Battery voltage representing a fully charged battery in the linear level mapping.
    constexpr BatteryVoltage BATTERY_VOLTAGE_FULL = 4.2f;

    /// Special voltage value indicating a battery voltage measurement error.
    constexpr BatteryVoltage BATTERY_VOLTAGE_MEASUREMENT_ERROR = -999.0f;

    /// Special voltage value indicating that no battery voltage has been measured yet.
    constexpr BatteryVoltage BATTERY_VOLTAGE_NOT_INITIALIZED = -100;

    /// Minimum valid battery level in percent.
    constexpr BatteryLevel BATTERY_LEVEL_MIN = 0;

    /// Maximum valid battery level in percent.
    constexpr BatteryLevel BATTERY_LEVEL_MAX = 100;

    /// Special battery level value indicating that no valid battery level is available.
    constexpr BatteryLevel BATTERY_LEVEL_NOT_INITIALIZED = 255;

    /// Dummy battery level used in tests.
    constexpr BatteryLevel BATTERY_LEVEL_DUMMY_VALID = 50;
}