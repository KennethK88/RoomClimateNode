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

/**
 * @brief GPIO pin used as an analog-to-digital converter input.
 */
using AdcPin = uint8_t;

/**
 * @brief General-purpose input/output pin.
 *
 * This type is used to represent microcontroller GPIO pins, for example
 * status LED pins or other digital input/output signals.
 */
using GpioPin = uint8_t;