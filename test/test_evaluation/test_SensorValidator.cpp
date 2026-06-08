#include <unity.h>
#include <SensorValidator.h>
#include <cmath>

void test_all_sensors_not_initialized_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
    measurements.humidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;
    
    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);

    // Assert
    TEST_ASSERT_FALSE(validationResults.temperatureValid);
    TEST_ASSERT_FALSE(validationResults.humidityValid);
}

void test_all_sensors_valid_values_should_be_valid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    
    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);

    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
}

void test_temperature_not_initialized_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    
    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);

    // Assert
    TEST_ASSERT_FALSE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
}

void test_temperature_equals_max_valid_should_be_valid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_MAX_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
}

void test_temperature_equals_min_valid_should_be_valid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_MIN_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
}

void test_temperature_equals_nan_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = NAN;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_FALSE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
}

void test_temperature_below_min_valid_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_MIN_VALID - 0.5f;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_FALSE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
}

void test_temperature_above_max_valid_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_MAX_VALID + 0.5f;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_FALSE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
}

void test_temperature_measurement_error_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_MEASUREMENT_ERROR;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    
    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);

    // Assert
    TEST_ASSERT_FALSE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
}

void test_humidity_not_initialized_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_FALSE(validationResults.humidityValid);
}

void test_humidity_equals_max_valid_should_be_valid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_MAX_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
}

void test_humidity_equals_min_valid_should_be_valid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_MIN_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
}

void test_humidity_equals_nan_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = NAN;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_FALSE(validationResults.humidityValid);
}

void test_humidity_below_min_valid_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_MIN_VALID - 0.5f;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_FALSE(validationResults.humidityValid);
}

void test_humidity_above_max_valid_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_MAX_VALID + 0.5f;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_FALSE(validationResults.humidityValid);
}

void test_humidity_measurement_error_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_MEASUREMENT_ERROR;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_FALSE(validationResults.humidityValid);
}