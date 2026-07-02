#pragma once

/**
 * @file PowerManager.h
 * @brief Power management component for ESP32 deep sleep handling.
 */

/**
 * @class PowerManager
 * @brief Configures wake-up sources and enters ESP32 deep sleep.
 *
 * The PowerManager encapsulates the platform-specific power management logic
 * required for low-power operation of the room climate node. It configures the
 * timer wake-up source and starts deep sleep after a measurement and publishing
 * cycle has completed.
 *
 * Responsibilities:
 * - Configure the ESP32 timer wake-up source
 * - Enter deep sleep mode
 *
 * @note After entering deep sleep, the ESP32 stops executing the application.
 * When the timer wake-up occurs, the application starts again from the normal
 * boot sequence.
 */
class PowerManager
{
    private:

        /**
         * @brief Configures the timer wake-up source for deep sleep.
         *
         * The wake-up interval is taken from the power configuration.
         *
         * @return true if the wake-up source was configured successfully,
         *         false otherwise.
         */
        bool configureWakeUp();

    public:

        /**
         * @brief Creates a power manager instance.
         */
        PowerManager() = default;

        /**
         * @brief Enters ESP32 deep sleep mode.
         *
         * The method first configures the timer wake-up source. If the wake-up
         * configuration fails, deep sleep is not entered.
         */
        void enterDeepSleep();
};