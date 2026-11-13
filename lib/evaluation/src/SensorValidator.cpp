#include "SensorValidator.h"

#include <cmath>
#include <BatteryConstants.h>

namespace
{
    bool validateSensor(float value, float init, float min, float max, float error)
    {
        return (!std::isnan(value) && (value != init) && (value != error) && (value >= min) && (value <= max));
    }

    bool validateSensor(BatteryLevel value, BatteryLevel init, BatteryLevel min, BatteryLevel max)
    {
        return ((value != init) && (value >= min) && (value <= max));
    }
}

void SensorValidator::validateTemperature(const Measurements& measurements, ValidationResults& validationResults)
{
    validationResults.temperatureValid = validateSensor(measurements.temperature,
                                            SensorConstants::TEMPERATURE_NOT_INITIALIZED,
                                            SensorConstants::TEMPERATURE_MIN_VALID,
                                            SensorConstants::TEMPERATURE_MAX_VALID,
                                            SensorConstants::TEMPERATURE_MEASUREMENT_ERROR);
}

void SensorValidator::validateHumidity(const Measurements& measurements, ValidationResults& validationResults) 
{
    validationResults.humidityValid = validateSensor(measurements.humidity,
                                        SensorConstants::HUMIDITY_NOT_INITIALIZED,
                                        SensorConstants::HUMIDITY_MIN_VALID,
                                        SensorConstants::HUMIDITY_MAX_VALID,
                                        SensorConstants::HUMIDITY_MEASUREMENT_ERROR);
}

void SensorValidator::validateBatteryLevel(const Measurements& measurements, ValidationResults& validationResults) 
{
    validationResults.batteryLevelValid = validateSensor(measurements.batteryLevel,
                                        BatteryConstants::BATTERY_LEVEL_NOT_INITIALIZED,
                                        BatteryConstants::BATTERY_LEVEL_MIN,
                                        BatteryConstants::BATTERY_LEVEL_MAX);
}

ValidationResults SensorValidator::validateAllSensors(const Measurements& measurements)
{
    ValidationResults validationResults;
    validateTemperature(measurements, validationResults);
    validateHumidity(measurements, validationResults);
    validateBatteryLevel(measurements, validationResults);
    return validationResults;
}