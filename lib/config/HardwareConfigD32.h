#pragma once
#include <Types.h>
#include <BatteryTypes.h>

/**
 * @file HardwareConfigD32.h
 * @brief Hardware-specific configuration values for the room climate node.
 *
 * This file contains board- and wiring-specific constants that describe how
 * external hardware is connected to the microcontroller, such as battery
 * voltage measurement and I2C sensor wiring.
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
     * @brief ESP32 GPIO pin used as I2C SDA line.
     *
     * This pin is used for the SHT31 sensor connection on the LOLIN D32.
     */
    constexpr GpioPin I2C_SDA_PIN = 14;

    /**
     * @brief ESP32 GPIO pin used as I2C SCL line.
     *
     * This pin is used for the SHT31 sensor connection on the LOLIN D32.
     */
    constexpr GpioPin I2C_SCL_PIN = 13;

    /**
     * @brief Voltage divider factor for calculating the actual battery voltage.
     *
     * The measured ADC pin voltage is multiplied by this factor to compensate
     * for the onboard voltage divider between the battery and the ADC input.
     */
    constexpr float BATTERY_VOLTAGE_DIVIDER_FACTOR = 2.0f;
}