#pragma once
#include <ValidationResults.h>
#include <Measurements.h>
#include <ThresholdResults.h>
#include <CommonSensorConstants.h>

class ThresholdEvaluator
{
    private:
        void evaluateTemperatureTooHigh(const Measurements& measurements, const ValidationResults& validationResults, ThresholdResults& thresholdResult);
        void evaluateHumidityTooHigh(const Measurements& measurements, const ValidationResults& validationResults, ThresholdResults& thresholdResult);
        void evaluateCoTooHigh(const Measurements& measurements, const ValidationResults& validationResults, ThresholdResults& thresholdResult);

        void evaluateTemperatureTooLow(const Measurements& measurements, const ValidationResults& validationResults, ThresholdResults& thresholdResult);
        void evaluateHumidityTooLow(const Measurements& measurements, const ValidationResults& validationResults, ThresholdResults& thresholdResult);
    
    public:
        ThresholdEvaluator() = default;
        ThresholdResults evaluateAllSensors(const Measurements& measurements, const ValidationResults& validationResults);
};