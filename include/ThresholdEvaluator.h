#pragma once
#include "ValidationResult.h"
#include "Measurements.h"
#include "ThresholdResult.h"
#include "CommonSensorConstants.h"

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