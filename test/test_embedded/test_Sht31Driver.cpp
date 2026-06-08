#include <unity.h>
#include <Sht31Driver.h>
#include <Types.h>

void test_sht31_driver_should_measure_room_temperature_range()
{
    // NOTE: Dieser Test setzt einen angeschlossenen SHT31 Sensor bei Raumtemperatur voraus.

    // Arrange
    Sht31Driver sht31Driver;
    sht31Driver.init();

    // Act
    sht31Driver.readMeasurements();
    Temperature temperature = sht31Driver.getTemperature();

    // Assert
    TEST_ASSERT_TRUE(temperature >= 15.0f && temperature <= 30.0f);
}

void test_sht31_driver_should_measure_room_humidity_range()
{
    // NOTE: Dieser Test setzt einen angeschlossenen SHT31 Sensor unter typischen Raumklimabedingungen voraus.

    // Arrange
    Sht31Driver sht31Driver;
    sht31Driver.init();

    // Act
    sht31Driver.readMeasurements();
    Humidity humidity = sht31Driver.getHumidity();

    // Assert
    TEST_ASSERT_TRUE(humidity >= 20.0f && humidity <= 80.0f);
}