#include <unity.h>
#include <DistanceDriver.h>
#include <CommonSensorConstants.h>
#include <cmath>

void test_distance_driver_distance_not_nan_should_be_true()
{
    // Arrange
    DistanceDriver distanceDriver;
    distanceDriver.init();

    // Act
    float distance = distanceDriver.getValue();

    // Assert
    TEST_ASSERT_TRUE(!std::isnan(distance));
}

void test_distance_driver_distance_should_be_within_plausible_range()
{
    // Arrange
    DistanceDriver distanceDriver;
    distanceDriver.init();

    // Act
    float distance = distanceDriver.getValue();

    // Assert
    TEST_ASSERT_TRUE(distance >= SensorConstants::DISTANCE_MIN_VALID && distance <= SensorConstants::DISTANCE_MAX_VALID);
}