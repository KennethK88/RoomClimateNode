#pragma once
#include <cstdint>

/**
 * @file Types.h
 * @brief Central type definitions used by the room climate node.
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
 * @brief General-purpose input/output pin.
 *
 * This type is used to represent microcontroller GPIO pins, for example
 * status LED pins or other digital input/output signals.
 */
using GpioPin = uint8_t;

/**
 * @brief Time duration in seconds.
 *
 * This type is used for human-readable time configuration values,
 * for example the deep sleep interval of the room climate node.
 */
using Seconds = uint16_t;

/**
 * @brief Time duration in microseconds.
 *
 * This type is used for timer-based ESP32 API calls, for example
 * the deep sleep timer wake-up configuration. The 64-bit width avoids
 * overflow when converting longer durations from seconds to microseconds.
 */
using Microseconds = uint64_t;

/**
 * @brief Time duration in milliseconds.
 *
 * This type is used for timeout and polling interval values, for example
 * during Wi-Fi or MQTT connection handling. It matches the return type used
 * by Arduino's millisecond time base.
 */
using Milliseconds = unsigned long;