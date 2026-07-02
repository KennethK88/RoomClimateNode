#pragma once
#include <Types.h>

/**
 * @file PowerConfig.h
 * @brief Power management configuration for the room climate node.
 */

/**
 * @brief Configuration values used for low-power operation.
 *
 * This namespace contains timing-related constants for the ESP32 deep sleep
 * cycle. The values define how long the node remains in deep sleep before it
 * wakes up again for the next measurement and publishing cycle.
 */
namespace PowerConfig
{
     /**
     * @brief Deep sleep duration in seconds.
     *
     * The room climate node wakes up after this interval, performs one
     * measurement and publishing cycle, and then returns to deep sleep.
     */
    constexpr Seconds DEEP_SLEEP_DURATION_SECONDS = 900;

    /**
     * @brief Number of microseconds per second.
     *
     * This value is used to convert the human-readable deep sleep duration
     * from seconds to microseconds for the ESP32 timer wake-up API.
     */
    constexpr Microseconds MICROSECONDS_PER_SECOND = 1000000;
}