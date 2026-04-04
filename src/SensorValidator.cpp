#include "SensorValidator.h"

static bool validateSensor(float value, float init, float min, float max)
{
    return ((value != init) && (value >= min) && (value <= max));
}

void SensorValidator::validateTemperature(const Measurements& measurements, ValidationResult& validationResult)
{
    validationResult.temperatureValid = validateSensor(measurements.temperature,
                                            SensorConstants::TEMPERATURE_NOT_INITIALIZED,
                                            SensorConstants::TEMPERATURE_MIN_VALID,
                                            SensorConstants::TEMPERATURE_MAX_VALID);
}

void SensorValidator::validateHumidity(const Measurements& measurements, ValidationResult& validationResult) 
{
    validationResult.humidityValid = validateSensor(measurements.humidity,
                                        SensorConstants::HUMIDITY_NOT_INITIALIZED,
                                        SensorConstants::HUMIDITY_MIN_VALID,
                                        SensorConstants::HUMIDITY_MAX_VALID);
}

void SensorValidator::validateCo(const Measurements& measurements, ValidationResult& validationResult)
{
    validationResult.coValid = validateSensor(measurements.co,
                                    SensorConstants::CO_NOT_INITIALIZED,
                                    SensorConstants::CO_MIN_VALID,
                                    SensorConstants::CO_MAX_VALID);
}

ValidationResult SensorValidator::validateAllSensors(const Measurements& measurements)
{
    ValidationResult validationResult;
    validateTemperature(measurements, validationResult);
    validateHumidity(measurements, validationResult);
    validateCo(measurements, validationResult);
    return validationResult;
}