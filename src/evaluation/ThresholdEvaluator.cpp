#include "evaluation/ThresholdEvaluator.h"

static bool evaluateSensorTooHigh(float value, float max, bool valid)
{
    return ((value >= max) && valid);
}

static bool evaluateSensorTooLow(float value, float min, bool valid)
{
    return ((value <= min) && valid);
}

void ThresholdEvaluator::evaluateTemperatureTooHigh(const Measurements& measurements, const ValidationResult& validationResult, ThresholdResults& thresholdResult)
{
    thresholdResult.temperatureTooHigh = evaluateSensorTooHigh(measurements.temperature, SensorConstants::TEMPERATURE_MAX_THRESHOLD, validationResult.temperatureValid);
}

void ThresholdEvaluator::evaluateHumidityTooHigh(const Measurements& measurements, const ValidationResult& validationResult, ThresholdResults& thresholdResult)
{
    thresholdResult.humidityTooHigh = evaluateSensorTooHigh(measurements.humidity, SensorConstants::HUMIDITY_MAX_THRESHOLD, validationResult.humidityValid);
}

void ThresholdEvaluator::evaluateCoTooHigh(const Measurements& measurements, const ValidationResult& validationResult, ThresholdResults& thresholdResult)
{
    thresholdResult.coTooHigh = evaluateSensorTooHigh(measurements.co, SensorConstants::CO_MAX_THRESHOLD, validationResult.coValid);
}

void ThresholdEvaluator::evaluateTemperatureTooLow(const Measurements& measurements, const ValidationResult& validationResult, ThresholdResults& thresholdResult)
{
    thresholdResult.temperatureTooLow = evaluateSensorTooLow(measurements.temperature, SensorConstants::TEMPERATURE_MIN_THRESHOLD, validationResult.temperatureValid);
}

void ThresholdEvaluator::evaluateHumidityTooLow(const Measurements& measurements, const ValidationResult& validationResult, ThresholdResults& thresholdResult)
{
    thresholdResult.humidityTooLow = evaluateSensorTooLow(measurements.humidity, SensorConstants::HUMIDITY_MIN_THRESHOLD, validationResult.humidityValid);    
}
    
ThresholdResults ThresholdEvaluator::evaluateAllSensors(const Measurements& measurements, const ValidationResult& validationResult)
{
    ThresholdResults thresholdResult;
    evaluateTemperatureTooHigh(measurements, validationResult, thresholdResult);
    evaluateHumidityTooHigh(measurements, validationResult, thresholdResult);
    evaluateCoTooHigh(measurements, validationResult, thresholdResult);
    evaluateTemperatureTooLow(measurements, validationResult, thresholdResult);
    evaluateHumidityTooLow(measurements, validationResult, thresholdResult);
    return thresholdResult;
}