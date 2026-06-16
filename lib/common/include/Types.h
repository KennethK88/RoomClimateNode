#pragma once
#include <cstdint>

/**
 * @file Types.h
 * @brief Zentrale Typdefinitionen für Messwerte des Raumklima-Knotens.
 */

/**
 * @brief Temperaturwert in Grad Celsius.
 */
using Temperature = float;

/**
 * @brief Relative Luftfeuchtigkeit in Prozent.
 */
using Humidity = float;

using BatteryVoltage = float;

using BatteryLevel = uint8_t;