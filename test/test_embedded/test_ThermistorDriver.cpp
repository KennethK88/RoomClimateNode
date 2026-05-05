#include <unity.h>
#include <ThermistorDriver.h>
#include <CommonSensorConstants.h>
#include <cmath>

void test_thermistor_temperature_not_nan_should_be_true()
{
    // Arrange
    ThermistorDriver thermistorDriver;
    thermistorDriver.init();

    // Act
    float temperature = thermistorDriver.getValue();

    // Assert
    TEST_ASSERT_TRUE(!std::isnan(temperature));
}

void test_thermistor_temperature_should_be_within_plausible_range()
{
    // Arrange
    ThermistorDriver thermistorDriver;
    thermistorDriver.init();

    // Act
    float temperature = thermistorDriver.getValue();

    // Assert
    TEST_ASSERT_TRUE(temperature >= SensorConstants::TEMPERATURE_MIN_VALID && temperature <= SensorConstants::TEMPERATURE_MAX_VALID);
}