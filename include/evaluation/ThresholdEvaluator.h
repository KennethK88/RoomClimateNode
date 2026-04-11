#pragma once
#include "data/ValidationResult.h"
#include "data/Measurements.h"
#include "data/ThresholdResult.h"
#include "utils/CommonSensorConstants.h"

class ThresholdEvaluator
{
    private:
        void evaluateTemperatureTooHigh(const Measurements& measurements, const ValidationResult& validationResult, ThresholdResult& thresholdResult);
        void evaluateHumidityTooHigh(const Measurements& measurements, const ValidationResult& validationResult, ThresholdResult& thresholdResult);
        void evaluateCoTooHigh(const Measurements& measurements, const ValidationResult& validationResult, ThresholdResult& thresholdResult);

        void evaluateTemperatureTooLow(const Measurements& measurements, const ValidationResult& validationResult, ThresholdResult& thresholdResult);
        void evaluateHumidityTooLow(const Measurements& measurements, const ValidationResult& validationResult, ThresholdResult& thresholdResult);
    
    public:
        ThresholdEvaluator() = default;
        ThresholdResult evaluateAllSensors(const Measurements& measurements, const ValidationResult& validationResult);
};