#pragma once
#include "utils/CommonSensorConstants.h"
#include "data/Measurements.h"
#include "data/ValidationResult.h"

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

