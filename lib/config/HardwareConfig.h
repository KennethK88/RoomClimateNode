#pragma once
#include <Types.h>

/**
 * @file HardwareConfig.h
 * @brief Hardware-specific configuration values for the room climate node.
 *
 * This file contains board- and wiring-specific constants that describe how
 * external hardware is connected to the microcontroller.
 */
namespace HardwareConfig
{
    /**
     * @brief ADC-capable GPIO pin used to measure the battery voltage.
     *
     * On the LOLIN D32, the battery voltage is connected to the ESP32 ADC
     * through an onboard voltage divider.
     */
    constexpr AdcPin BATTERY_ADC_PIN = 35;

    /**
     * @brief Voltage divider factor for calculating the actual battery voltage.
     *
     * The measured ADC pin voltage is multiplied by this factor to compensate
     * for the onboard voltage divider between the battery and the ADC input.
     */
    constexpr float BATTERY_VOLTAGE_DIVIDER_FACTOR = 2.0f;
}