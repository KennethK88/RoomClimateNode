#include <ThresholdEvaluator.h>

static bool evaluateSensorTooHigh(float value, float max, bool valid)
{
    return ((value >= max) && valid);
}

static bool evaluateSensorTooLow(float value, float min, bool valid)
{
    return ((value <= min) && valid);
}

void ThresholdEvaluator::evaluateTemperatureTooHigh(const Measurements& measurements, const ValidationResults& validationResults, ThresholdResults& thresholdResult)
{
    thresholdResult.temperatureTooHigh = evaluateSensorTooHigh(measurements.temperature, SensorConstants::TEMPERATURE_MAX_THRESHOLD, validationResults.temperatureValid);
}

void ThresholdEvaluator::evaluateHumidityTooHigh(const Measurements& measurements, const ValidationResults& validationResults, ThresholdResults& thresholdResult)
{
    thresholdResult.humidityTooHigh = evaluateSensorTooHigh(measurements.humidity, SensorConstants::HUMIDITY_MAX_THRESHOLD, validationResults.humidityValid);
}

void ThresholdEvaluator::evaluateCoTooHigh(const Measurements& measurements, const ValidationResults& validationResults, ThresholdResults& thresholdResult)
{
    thresholdResult.coTooHigh = evaluateSensorTooHigh(measurements.co, SensorConstants::CO_MAX_THRESHOLD, validationResults.coValid);
}

void ThresholdEvaluator::evaluateTemperatureTooLow(const Measurements& measurements, const ValidationResults& validationResults, ThresholdResults& thresholdResult)
{
    thresholdResult.temperatureTooLow = evaluateSensorTooLow(measurements.temperature, SensorConstants::TEMPERATURE_MIN_THRESHOLD, validationResults.temperatureValid);
}

void ThresholdEvaluator::evaluateHumidityTooLow(const Measurements& measurements, const ValidationResults& validationResults, ThresholdResults& thresholdResult)
{
    thresholdResult.humidityTooLow = evaluateSensorTooLow(measurements.humidity, SensorConstants::HUMIDITY_MIN_THRESHOLD, validationResults.humidityValid);    
}
    
ThresholdResults ThresholdEvaluator::evaluateAllSensors(const Measurements& measurements, const ValidationResults& validationResults)
{
    ThresholdResults thresholdResult;
    evaluateTemperatureTooHigh(measurements, validationResults, thresholdResult);
    evaluateHumidityTooHigh(measurements, validationResults, thresholdResult);
    evaluateCoTooHigh(measurements, validationResults, thresholdResult);
    evaluateTemperatureTooLow(measurements, validationResults, thresholdResult);
    evaluateHumidityTooLow(measurements, validationResults, thresholdResult);
    return thresholdResult;
}