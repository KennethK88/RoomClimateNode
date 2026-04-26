#pragma once
#include <CommonSensorConstants.h>
#include <Measurements.h>
#include <ValidationResults.h>

class SensorValidator
{
    private:
        void validateTemperature(const Measurements& measurements, ValidationResults& validationResults);
        void validateHumidity(const Measurements& measurements, ValidationResults& validationResults);
        void validateCo(const Measurements& measurements, ValidationResults& validationResults);
        void validateDistance(const Measurements& measurements, ValidationResults& validationResults);

    public:
        SensorValidator() = default;
        ValidationResults validateAllSensors(const Measurements& measurements);
};

