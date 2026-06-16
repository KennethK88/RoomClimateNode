#pragma once
#include <IBatteryDriver.h>
#include <Types.h>
#include <BatteryConstants.h>

/**
 * @file ESP32BatteryDriver.h
 * @brief ESP32-specific driver for battery voltage measurement.
 */

/**
 * @class ESP32BatteryDriver
 * @brief Reads and stores the current battery voltage.
 *
 * The ESP32BatteryDriver provides the hardware-specific implementation of the
 * IBatteryDriver interface. It is responsible for reading the battery voltage
 * through an analog input and storing the latest measured value internally.
 *
 * The stored voltage can then be used by higher-level components such as the
 * BatterySensor to calculate a battery level percentage.
 *
 * @note Until a voltage has been read successfully, the driver returns
 * BatteryConstants::BATTERY_VOLTAGE_NOT_INITIALIZED.
 */
class ESP32BatteryDriver : public IBatteryDriver
{
    private:

        /**
         * @brief Last measured battery voltage in volts.
         */
        BatteryVoltage batteryVoltage = BatteryConstants::BATTERY_VOLTAGE_NOT_INITIALIZED;
        
    public:

        /**
         * @brief Creates a new battery driver instance.
         */
        ESP32BatteryDriver() = default;

        /**
         * @brief Initializes the battery voltage measurement hardware.
         *
         * This may configure the required analog input or related hardware
         * resources depending on the target platform.
         */
        void init() override;

        /**
         * @brief Reads the current battery voltage and stores it internally.
         *
         * The measured voltage can be retrieved afterwards using getVoltage().
         */
        void readVoltage() override;

        /**
         * @brief Returns the last measured battery voltage.
         *
         * @return Last measured battery voltage in volts, or
         * BatteryConstants::BATTERY_VOLTAGE_NOT_INITIALIZED if no voltage has
         * been read yet.
         */
        BatteryVoltage getVoltage() override;
};