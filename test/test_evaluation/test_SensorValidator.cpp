#include <unity.h>
#include <SensorValidator.h>

void test_temperature_not_initialized_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
    measurements.humidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;
    measurements.co = SensorConstants::CO_NOT_INITIALIZED;
    
    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);

    // Assert
    TEST_ASSERT_FALSE(validationResults.temperatureValid);
}

void test_humidity_not_initialized_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
    measurements.humidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;
    measurements.co = SensorConstants::CO_NOT_INITIALIZED;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_FALSE(validationResults.humidityValid);
}

void test_co_not_initialized_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
    measurements.humidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;
    measurements.co = SensorConstants::CO_NOT_INITIALIZED;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_FALSE(validationResults.coValid);
}