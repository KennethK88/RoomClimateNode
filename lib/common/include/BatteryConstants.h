#pragma once
#include <Types.h>

namespace BatteryConstants
{
    constexpr BatteryVoltage BATTERY_VOLTAGE_EMPTY = 3.0f;
    constexpr BatteryVoltage BATTERY_VOLTAGE_FULL = 4.2f;
    constexpr BatteryVoltage BATTERY_VOLTAGE_MEASUREMENT_ERROR = -999.0f;
    constexpr BatteryVoltage BATTERY_VOLTAGE_NOT_INITIALIZED = -100;

    constexpr BatteryLevel BATTERY_LEVEL_MIN = 0;
    constexpr BatteryLevel BATTERY_LEVEL_MAX = 100;
    constexpr BatteryLevel BATTERY_LEVEL_NOT_INITIALIZED = 255;
}