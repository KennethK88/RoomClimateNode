#include <unity.h>
#include <DistanceDriver.h>
#include <CommonSensorConstants.h>

void test_distance_driver_should_measure_distance_with_object_present()
{
    // NOTE: Dieser Embedded-Test setzt einen angeschlossenen Ultraschallsensor und ein Objekt im Messbereich voraus.

    // Arrange
    DistanceDriver distanceDriver;
    distanceDriver.init();

    // Act
    float distance = distanceDriver.getValue();

    // Assert
    TEST_ASSERT_TRUE(distance > SensorConstants::DISTANCE_MIN_VALID && distance <= SensorConstants::DISTANCE_MAX_VALID);
    // NOTE: ">" bewusst gewählt, da 0.0f auf fehlendes Echo / nicht angeschlossenen Sensor hinweist
}