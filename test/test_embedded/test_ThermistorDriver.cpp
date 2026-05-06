#include <unity.h>
#include <ThermistorDriver.h>

void test_thermistor_driver_should_measure_room_temperature_range()
{
    // NOTE: Dieser Test setzt einen angeschlossenen Thermistor bei Raumtemperatur voraus.

    // Arrange
    ThermistorDriver thermistorDriver;
    thermistorDriver.init();

    // Act
    float temperature = thermistorDriver.getValue();

    // Assert
    TEST_ASSERT_TRUE(temperature >= 15.0f && temperature <= 30.0f);
}