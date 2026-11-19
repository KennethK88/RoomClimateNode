#include "Sht31Driver.h"
#include "Types.h"

#include <unity.h>

namespace
{
    constexpr Temperature MIN_ROOM_TEMPERATURE = 15.0f;
    constexpr Temperature MAX_ROOM_TEMPERATURE = 30.0f;
    constexpr Humidity MIN_ROOM_HUMIDITY = 20.0f;
    constexpr Humidity MAX_ROOM_HUMIDITY = 80.0f;
}

void test_sht31_driver_should_measure_room_temperature_range()
{
    // NOTE: This test requires a connected SHT31 sensor under typical room temperature conditions.

    // Arrange
    Sht31Driver sht31Driver;
    sht31Driver.init();

    // Act
    sht31Driver.readMeasurements();
    const Temperature temperature = sht31Driver.getTemperature();

    // Assert
    TEST_ASSERT_GREATER_OR_EQUAL_FLOAT(MIN_ROOM_TEMPERATURE, temperature);
    TEST_ASSERT_LESS_OR_EQUAL_FLOAT(MAX_ROOM_TEMPERATURE, temperature);
}

void test_sht31_driver_should_measure_room_humidity_range()
{
    // NOTE: This test requires a connected SHT31 sensor under typical indoor humidity conditions.

    // Arrange
    Sht31Driver sht31Driver;
    sht31Driver.init();

    // Act
    sht31Driver.readMeasurements();
    const Humidity humidity = sht31Driver.getHumidity();

    // Assert
    TEST_ASSERT_GREATER_OR_EQUAL_FLOAT(MIN_ROOM_HUMIDITY, humidity);
    TEST_ASSERT_LESS_OR_EQUAL_FLOAT(MAX_ROOM_HUMIDITY, humidity);
}