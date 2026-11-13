#pragma once

/**
 * @file PowerManager.h
 * @brief Defines the power management component for ESP32 deep sleep operation.
 */

/**
 * @brief Configures timer-based wake-up and manages deep sleep.
 *
 * Encapsulates the platform-specific deep sleep functionality for the
 * RoomClimateNode on supported ESP32 platforms.
 *
 * The PowerManager configures the timer wake-up source and transitions
 * the microcontroller into deep sleep after a measurement and publishing cycle.
 *
 * @note Waking up from deep sleep causes a new application startup rather
 * than resuming execution at the point where deep sleep was entered.
 */
class PowerManager
{
    private:

        /**
         * @brief Configures the timer wake-up source.
         *
         * Uses the configured deep sleep duration to set the
         * timer-based wake-up interval.
         *
         * @return true if configuration succeeds, false otherwise.
         */
        bool configureWakeUp();

    public:

        /**
         * @brief Constructs a power manager instance.
         */
        PowerManager() = default;

        /**
         * @brief Configures wake-up and enters deep sleep.
         *
         * Attempts to configure the timer wake-up source before
         * entering deep sleep.
         *
         * If wake-up configuration fails, deep sleep is not entered.
         */
        void enterDeepSleep();
};