#include <unity.h>
#include <ESP32BatteryDriver.h>
#include <Types.h>
#include <BatteryConstants.h>

void test_esp32_battery_driver_should_measure_battery_voltage_in_valid_range()
{
    // NOTE: This test requires a connected battery and a working analog voltage measurement circuit.

    // Arrange
    ESP32BatteryDriver esp32BatteryDriver;
    esp32BatteryDriver.init();

    // Act
    esp32BatteryDriver.readVoltage();
    BatteryVoltage batteryVoltage = esp32BatteryDriver.getVoltage();

    // Assert
    TEST_ASSERT_GREATER_OR_EQUAL_FLOAT(BatteryConstants::BATTERY_VOLTAGE_EMPTY, batteryVoltage);
    TEST_ASSERT_LESS_OR_EQUAL_FLOAT(BatteryConstants::BATTERY_VOLTAGE_FULL, batteryVoltage);
}