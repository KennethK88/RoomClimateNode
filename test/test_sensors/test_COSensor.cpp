#include <unity.h>
#include <COSensor.h>

const float epsilon = 0.1f;

void test_co_sensor_not_initialized_value_should_be_not_initialized()
{
    // Arrange
    COSensor coSensor;

    // Act
    float coValue = coSensor.getCO();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, SensorConstants::CO_NOT_INITIALIZED, coValue);
}

void test_co_sensor_initialized_value_should_be_dummy_value()
{
    // TODO: Test nach Umstellung auf Interface anpassen
    // Arrange
    COSensor coSensor;

    // Act
    coSensor.readCO();
    float coValue = coSensor.getCO();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 20.f, coValue);
}