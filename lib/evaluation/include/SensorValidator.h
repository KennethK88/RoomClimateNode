#pragma once

#include "Measurements.h"
#include "ValidationResults.h"

/**
 * @file SensorValidator.h
 * @brief Defines the validation component for RoomClimateNode measurements.
 */

/**
 * @brief Validates temperature, humidity, and battery level measurements.
 *
 * Evaluates sensor measurements against application-specific validation rules
 * to identify uninitialized, erroneous, or implausible values.
 *
 * The validation results are provided as individual flags within a
 * ValidationResults structure, allowing each measurement to be
 * evaluated independently.
 */
class SensorValidator
{
    private:

        /**
         * @brief Validates the temperature measurement.
         *
         * @param measurements Measurement values to validate.
         * @param validationResults Structure receiving the validation result.
         */
        void validateTemperature(const Measurements& measurements, ValidationResults& validationResults);

        /**
         * @brief Validates the relative humidity measurement.
         *
         * @param measurements Measurement values to validate.
         * @param validationResults Structure receiving the validation result.
         */   
        void validateHumidity(const Measurements& measurements, ValidationResults& validationResults);

        /**
         * @brief Validates the battery level measurement.
         *
         * @param measurements Measurement values to validate.
         * @param validationResults Structure receiving the validation result.
         */
        void validateBatteryLevel(const Measurements& measurements, ValidationResults& validationResults);

    public:

        /**
         * @brief Validates all measurements and returns their validation results.
         *
         * Evaluates temperature, relative humidity, and battery level
         * measurements independently.
         *
         * @param measurements Measurement values to validate.
         * @return Validation results for all measurements.
         */
        ValidationResults validateAllSensors(const Measurements& measurements);
};