#pragma once
#include "CommonSensorConstants.h"
#include "Measurements.h"
#include "ValidationResult.h"

class SensorValidator
{
    private:
        void validateTemperature(const Measurements& measurements, ValidationResult& validationResult);
        void validateHumidity(const Measurements& measurements, ValidationResult& validationResult);
        void validateCo(const Measurements& measurements, ValidationResult& validationResult);

    public:
        SensorValidator() = default;
        ValidationResult validateAllSensors(const Measurements& measurements);
};

