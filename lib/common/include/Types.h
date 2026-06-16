#pragma once
#include <cstdint>

/**
 * @file Types.h
 * @brief Central type definitions for measurement values used by the room climate node.
 */

/**
 * @brief Temperature value in degrees Celsius.
 */
using Temperature = float;

/**
 * @brief Relative humidity value in percent.
 */
using Humidity = float;

/**
 * @brief Battery voltage value in volts.
 */
using BatteryVoltage = float;

/**
 * @brief Battery level value in percent.
 *
 * Valid battery level values are in the range from 0 to 100.
 * Special values such as 255 may be used to indicate invalid or uninitialized states.
 */
using BatteryLevel = uint8_t;