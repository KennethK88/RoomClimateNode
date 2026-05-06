#include <unity.h>
#include <HumidityDriver.h>

void test_humidity_driver_should_measure_room_humidity_range()
{
    // NOTE: Dieser Test setzt einen angeschlossenen Feuchtesensor unter typischen Raumklimabedingungen voraus.

    // Arrange
    HumidityDriver humidityDriver;
    humidityDriver.init();

    // Act
    float humidity = humidityDriver.getValue();

    // Assert
    TEST_ASSERT_TRUE(humidity >= 20.0f && humidity <= 80.0f);
}