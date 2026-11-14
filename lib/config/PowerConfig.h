#pragma once

#include "Types.h"

/**
 * @file PowerConfig.h
 * @brief Defines power management configuration values for the RoomClimateNode.
 */

/**
 * @brief Contains configuration constants for low-power operation.
 *
 * Defines the deep sleep duration and the time conversion factor
 * required for configuring the ESP32 timer wake-up.
 */
namespace PowerConfig
{
    /**
     * @brief Deep sleep duration in seconds.
     *
     * The RoomClimateNode wakes up after this interval to perform
     * a measurement and publishing cycle before returning to deep sleep.
     */
    constexpr Seconds DEEP_SLEEP_DURATION_SECONDS = 900;

    /**
     * @brief Number of microseconds per second.
     *
     * Used to convert the deep sleep duration from seconds to
     * microseconds as required by the ESP32 timer wake-up API.
     */
    constexpr Microseconds MICROSECONDS_PER_SECOND = 1000000;
}