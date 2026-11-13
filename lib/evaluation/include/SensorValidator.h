#pragma once
#include "Measurements.h"
#include "ValidationResults.h"

/**
 * @file SensorValidator.h
 * @brief Validates measurement values of the room climate node.
 */

/**
 * @class SensorValidator
 * @brief Checks measurement values for initialization state, error values and valid value ranges.
 *
 * The SensorValidator evaluates the acquired measurement values using defined
 * validation rules and marks each value as valid or invalid.
 *
 * Its purpose is to detect uninitialized, erroneous or implausible measurement
 * values early and provide the result to downstream components in a structured
 * form.
 */
class SensorValidator
{
    private:

        /**
         * @brief Validates the temperature value.
         *
         * @param measurements Current measurement values.
         * @param validationResults Result structure used to store the validation status.
         */
        void validateTemperature(const Measurements& measurements, ValidationResults& validationResults);

         /**
         * @brief Validates the relative humidity value.
         *
         * @param measurements Current measurement values.
         * @param validationResults Result structure used to store the validation status.
         */     
        void validateHumidity(const Measurements& measurements, ValidationResults& validationResults);

        /**
         * @brief Validates the battery level value.
         *
         * @param measurements Current measurement values.
         * @param validationResults Result structure used to store the validation status.
         */
        void validateBatteryLevel(const Measurements& measurements, ValidationResults& validationResults);

    public:

        /**
         * @brief Validates all measurement values.
         *
         * Performs validation for all values contained in the Measurements object
         * and combines the results in a common ValidationResults structure.
         *
         * @param measurements Current measurement values.
         * @return Structure containing the validation status of all measurement values.
         */
        ValidationResults validateAllSensors(const Measurements& measurements);
};