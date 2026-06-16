#pragma once

/**
 * @file ValidationResults.h
 * @brief Data structure for the validation status of measurement values.
 *
 * This structure contains one validation flag for each relevant measurement
 * value. The flags indicate whether the corresponding value has been evaluated
 * as valid.
 *
 * The values are set by the SensorValidator and are used as the basis for
 * calculating the system state in the StateMachine.
 */
struct ValidationResults
{
    /**
     * @brief Indicates whether the temperature value is valid.
     */
    bool temperatureValid = false;

    /**
     * @brief Indicates whether the relative humidity value is valid.
     */
    bool humidityValid = false;

    /**
     * @brief Indicates whether the battery level value is valid.
     */
    bool batteryLevelValid = false;
};