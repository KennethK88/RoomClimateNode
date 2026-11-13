#pragma once

#include <cstdint>

/**
 * @file Types.h
 * @brief Defines common data types used by the RoomClimateNode.
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
 * @brief Microcontroller GPIO pin identifier.
 *
 * Used to identify GPIO pins for digital input and output signals.
 */
using GpioPin = uint8_t;

/**
 * @brief Time duration in seconds.
 *
 * Used for time configuration values, such as the deep sleep interval.
 */
using Seconds = uint16_t;

/**
 * @brief Time duration in microseconds.
 *
 * Used for ESP32 timer APIs, particularly deep sleep wake-up configuration.
 * The 64-bit representation prevents overflow when converting longer
 * durations from seconds to microseconds.
 */
using Microseconds = uint64_t;

/**
 * @brief Time duration in milliseconds.
 *
 * Used for timeouts and polling intervals.
 * Matches the return type of Arduino's millis() function.
 */
using Milliseconds = unsigned long;