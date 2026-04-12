#pragma once
#include "data/ValidationResults.h"
#include "data/Measurements.h"
#include "data/ThresholdResults.h"
#include "utils/CommonSensorConstants.h"

class ThresholdEvaluator
{
    private:
        void evaluateTemperatureTooHigh(const Measurements& measurements, const ValidationResults& validationResult, ThresholdResults& thresholdResult);
        void evaluateHumidityTooHigh(const Measurements& measurements, const ValidationResults& validationResult, ThresholdResults& thresholdResult);
        void evaluateCoTooHigh(const Measurements& measurements, const ValidationResults& validationResult, ThresholdResults& thresholdResult);

        void evaluateTemperatureTooLow(const Measurements& measurements, const ValidationResults& validationResult, ThresholdResults& thresholdResult);
        void evaluateHumidityTooLow(const Measurements& measurements, const ValidationResults& validationResult, ThresholdResults& thresholdResult);
    
    public:
        ThresholdEvaluator() = default;
        ThresholdResults evaluateAllSensors(const Measurements& measurements, const ValidationResults& validationResult);
};