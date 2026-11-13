#pragma once

#include "Types.h"

#include <BatteryTypes.h>

/**
 * @file HardwareConfigC3Pico.h
 * @brief Defines hardware-specific configuration values for the LOLIN C3 Pico.
 *
 * Contains board-specific GPIO assignments and configuration values for
 * battery voltage measurement and SHT31 sensor communication.
 */
namespace HardwareConfig
{
    /**
     * @brief ADC-capable GPIO pin used to measure the battery voltage.
     *
     * The LOLIN C3 Pico provides battery voltage measurement through
     * an onboard voltage divider connected to GPIO3.
     */
    constexpr AdcPin BATTERY_ADC_PIN = 3;

    /**
     * @brief GPIO pin used as the I2C SDA line.
     *
     * Connects the LOLIN C3 Pico to the SHT31 sensor.
     */
    constexpr GpioPin I2C_SDA_PIN = 8;

    /**
     * @brief GPIO pin used as the I2C SCL line.
     *
     * Connects the LOLIN C3 Pico to the SHT31 sensor.
     */
    constexpr GpioPin I2C_SCL_PIN = 10;

    /**
     * @brief Voltage divider factor for battery voltage calculation.
     *
     * The measured ADC voltage is multiplied by this factor to
     * compensate for the onboard battery voltage divider.
     */
    constexpr float BATTERY_VOLTAGE_DIVIDER_FACTOR = 2.0f;
}