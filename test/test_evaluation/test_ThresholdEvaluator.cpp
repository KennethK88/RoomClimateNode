#include <unity.h>
#include <ThresholdEvaluator.h>

void test_temperature_valid_and_within_thresholds_should_not_trigger_any_threshold_flags()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = false;
    validationResults.coValid = false;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh);
}

void test_temperature_valid_and_equals_max_threshold_should_trigger_too_high_flag()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_MAX_THRESHOLD;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = false;
    validationResults.coValid = false;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_TRUE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh);
}

void test_temperature_valid_and_equals_min_threshold_should_trigger_too_low_flag()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_MIN_THRESHOLD;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = false;
    validationResults.coValid = false;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_TRUE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh);   
}

void test_temperature_valid_and_below_min_threshold_should_trigger_too_low_flag()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_MIN_THRESHOLD - 0.5f;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = false;
    validationResults.coValid = false;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_TRUE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh); 
}

void test_temperature_valid_and_above_max_threshold_should_trigger_too_high_flag()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_MAX_THRESHOLD + 0.5f;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = false;
    validationResults.coValid = false;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_TRUE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh); 
}

void test_temperature_invalid_and_below_min_threshold_should_not_trigger_any_threshold_flags()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_MIN_THRESHOLD - 0.5f;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    validationResults.temperatureValid = false;
    validationResults.humidityValid = true;
    validationResults.coValid = true;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh); 
}

void test_temperature_invalid_and_above_max_threshold_should_not_trigger_any_threshold_flags()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_MAX_THRESHOLD + 0.5f;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    validationResults.temperatureValid = false;
    validationResults.humidityValid = true;
    validationResults.coValid = true;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh);
}

void test_humidity_valid_and_within_thresholds_should_not_trigger_any_threshold_flags()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    validationResults.temperatureValid = false;
    validationResults.humidityValid = true;
    validationResults.coValid = false;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh);
}

void test_humidity_valid_and_equals_max_threshold_should_trigger_too_high_flag()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_MAX_THRESHOLD;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    validationResults.temperatureValid = false;
    validationResults.humidityValid = true;
    validationResults.coValid = false;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_TRUE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh);
}

void test_humidity_valid_and_equals_min_threshold_should_trigger_too_low_flag()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_MIN_THRESHOLD;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    validationResults.temperatureValid = false;
    validationResults.humidityValid = true;
    validationResults.coValid = false;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_TRUE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh);   
}

void test_humidity_valid_and_below_min_threshold_should_trigger_too_low_flag()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_MIN_THRESHOLD - 0.5f;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    validationResults.temperatureValid = false;
    validationResults.humidityValid = true;
    validationResults.coValid = false;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_TRUE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh); 
}

void test_humidity_valid_and_above_max_threshold_should_trigger_too_high_flag()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_MAX_THRESHOLD + 0.5f;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    validationResults.temperatureValid = false;
    validationResults.humidityValid = true;
    validationResults.coValid = false;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_TRUE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh); 
}

void test_humidity_invalid_and_below_min_threshold_should_not_trigger_any_threshold_flags()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_MIN_THRESHOLD - 0.5f;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = false;
    validationResults.coValid = true;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh); 
}

void test_humidity_invalid_and_above_max_threshold_should_not_trigger_any_threshold_flags()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_MAX_THRESHOLD + 0.5f;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = false;
    validationResults.coValid = true;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh);
}

void test_co_valid_and_within_thresholds_should_not_trigger_any_threshold_flags()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;

    validationResults.temperatureValid = false;
    validationResults.humidityValid = false;
    validationResults.coValid = true;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh);
}

void test_co_valid_and_equals_max_threshold_should_trigger_too_high_flag()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_MAX_THRESHOLD;

    validationResults.temperatureValid = false;
    validationResults.humidityValid = false;
    validationResults.coValid = true;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_TRUE(thresholdResults.coTooHigh);
}

void test_co_valid_and_above_max_threshold_should_trigger_too_high_flag()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_MAX_THRESHOLD + 0.5f;

    validationResults.temperatureValid = false;
    validationResults.humidityValid = false;
    validationResults.coValid = true;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_TRUE(thresholdResults.coTooHigh); 
}

void test_co_invalid_and_above_max_threshold_should_not_trigger_any_threshold_flags()
{
    // Arrange
    ThresholdEvaluator thresholdEvaluator;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_MAX_THRESHOLD + 0.5f;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = true;
    validationResults.coValid = false;

    // Act
    ThresholdResults thresholdResults = thresholdEvaluator.evaluateAllSensors(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.temperatureTooLow);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooHigh);
    TEST_ASSERT_FALSE(thresholdResults.humidityTooLow);
    TEST_ASSERT_FALSE(thresholdResults.coTooHigh);
}
