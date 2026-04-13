#include <unity.h>
#include <SensorValidator.h>

void test_all_sensors_not_initialized_should_be_invalid()
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
    TEST_ASSERT_FALSE(validationResults.humidityValid);
    TEST_ASSERT_FALSE(validationResults.coValid);
}

void test_all_sensors_valid_values_should_be_valid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;
    
    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);

    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
    TEST_ASSERT_TRUE(validationResults.coValid);
}

void test_temperature_not_initialized_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;
    
    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);

    // Assert
    TEST_ASSERT_FALSE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
    TEST_ASSERT_TRUE(validationResults.coValid);
}

void test_temperature_equals_max_valid_should_be_valid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_MAX_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
    TEST_ASSERT_TRUE(validationResults.coValid);
}

void test_temperature_equals_min_valid_should_be_valid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_MIN_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
    TEST_ASSERT_TRUE(validationResults.coValid);
}

void test_temperature_below_min_valid_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_MIN_VALID - 0.5f;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_FALSE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
    TEST_ASSERT_TRUE(validationResults.coValid);
}

void test_temperature_above_max_valid_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_MAX_VALID + 0.5f;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_FALSE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
    TEST_ASSERT_TRUE(validationResults.coValid);
}

void test_humidity_not_initialized_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_FALSE(validationResults.humidityValid);
    TEST_ASSERT_TRUE(validationResults.coValid);
}

void test_humidity_equals_max_valid_should_be_valid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_MAX_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
    TEST_ASSERT_TRUE(validationResults.coValid);
}

void test_humidity_equals_min_valid_should_be_valid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_MIN_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
    TEST_ASSERT_TRUE(validationResults.coValid);
}

void test_humidity_below_min_valid_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_MIN_VALID - 0.5f;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_FALSE(validationResults.humidityValid);
    TEST_ASSERT_TRUE(validationResults.coValid);
}

void test_humidity_above_max_valid_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_MAX_VALID + 0.5f;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_FALSE(validationResults.humidityValid);
    TEST_ASSERT_TRUE(validationResults.coValid);
}

void test_co_not_initialized_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_NOT_INITIALIZED;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
    TEST_ASSERT_FALSE(validationResults.coValid);
}

void test_co_equals_max_valid_should_be_valid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_MAX_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
    TEST_ASSERT_TRUE(validationResults.coValid);
}

void test_co_equals_min_valid_should_be_valid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_MIN_VALID;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
    TEST_ASSERT_TRUE(validationResults.coValid);
}

void test_co_below_min_valid_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_MIN_VALID - 0.5f;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
    TEST_ASSERT_FALSE(validationResults.coValid);
}

void test_co_above_max_valid_should_be_invalid()
{
    // Arrange
    SensorValidator sensorValidator;
    Measurements measurements;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_MAX_VALID + 0.5f;

    // Act
    ValidationResults validationResults = sensorValidator.validateAllSensors(measurements);
    
    // Assert
    TEST_ASSERT_TRUE(validationResults.temperatureValid);
    TEST_ASSERT_TRUE(validationResults.humidityValid);
    TEST_ASSERT_FALSE(validationResults.coValid);
}
