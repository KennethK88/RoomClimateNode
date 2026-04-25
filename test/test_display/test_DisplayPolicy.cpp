#include <unity.h>
#include <DisplayPolicy.h>

void test_distance_invalid_display_should_be_active()
{
    // Arrange
    DisplayPolicy displayPolicy;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;
    measurements.distance = SensorConstants::DISTANCE_DUMMY_VALID;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = true;
    validationResults.coValid = true;
    validationResults.distanceValid = false;

    // Act
    bool displayActive = displayPolicy.isDisplayActive(measurements, validationResults);

    // Assert
    TEST_ASSERT_TRUE(displayActive);
}

void test_distance_valid_and_value_equals_on_off_threshold_display_should_be_active()
{
    // Arrange
    DisplayPolicy displayPolicy;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;
    measurements.distance = SensorConstants::DISTANCE_ON_OFF_THRESHOLD;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = true;
    validationResults.coValid = true;
    validationResults.distanceValid = true;

    // Act
    bool displayActive = displayPolicy.isDisplayActive(measurements, validationResults);

    // Assert
    TEST_ASSERT_TRUE(displayActive);
}

void test_distance_valid_and_value_below_on_off_threshold_display_should_be_active()
{
    // Arrange
    DisplayPolicy displayPolicy;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;
    measurements.distance = SensorConstants::DISTANCE_ON_OFF_THRESHOLD - 0.5f;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = true;
    validationResults.coValid = true;
    validationResults.distanceValid = true;

    // Act
    bool displayActive = displayPolicy.isDisplayActive(measurements, validationResults);

    // Assert
    TEST_ASSERT_TRUE(displayActive);
}

void test_distance_valid_and_value_above_on_off_threshold_display_should_be_inactive()
{
    // Arrange
    DisplayPolicy displayPolicy;
    Measurements measurements;
    ValidationResults validationResults;

    measurements.temperature = SensorConstants::TEMPERATURE_DUMMY_VALID;
    measurements.humidity = SensorConstants::HUMIDITY_DUMMY_VALID;
    measurements.co = SensorConstants::CO_DUMMY_VALID;
    measurements.distance = SensorConstants::DISTANCE_ON_OFF_THRESHOLD + 0.5f;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = true;
    validationResults.coValid = true;
    validationResults.distanceValid = true;

    // Act
    bool displayActive = displayPolicy.isDisplayActive(measurements, validationResults);

    // Assert
    TEST_ASSERT_FALSE(displayActive);
}