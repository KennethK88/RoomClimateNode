#pragma once
#include <CommonSensorConstants.h>
#include "data/Measurements.h"
#include "data/ValidationResults.h"

class SensorValidator
{
    private:
        void validateTemperature(const Measurements& measurements, ValidationResults& validationResult);
        void validateHumidity(const Measurements& measurements, ValidationResults& validationResult);
        void validateCo(const Measurements& measurements, ValidationResults& validationResult);

    public:
        SensorValidator() = default;
        ValidationResults validateAllSensors(const Measurements& measurements);
};

