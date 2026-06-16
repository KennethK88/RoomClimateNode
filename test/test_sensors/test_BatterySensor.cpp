#include <unity.h>
#include <BatterySensor.h>
#include <IBatteryDriver.h>
#include <BatteryConstants.h>

namespace
{
    class FakeBatteryDriver : public IBatteryDriver
    {
        public:
            BatteryVoltage currentDriverVoltage = BatteryConstants::BATTERY_VOLTAGE_NOT_INITIALIZED;
            void init() override {}
            void readVoltage() override {}
            BatteryVoltage getVoltage() override {return currentDriverVoltage;}
    };
}

void test_battery_voltage_not_initialized_should_be_not_initialized()
{
    // Arrange
    FakeBatteryDriver fakeBatteryDriver;
    BatterySensor batterySensor(fakeBatteryDriver);

    // Act
    BatteryLevel batteryLevel = batterySensor.getBatteryLevel();

    // Assert
    TEST_ASSERT_EQUAL_UINT8(BatteryConstants::BATTERY_LEVEL_NOT_INITIALIZED, batteryLevel);
}

void test_battery_voltage_measurement_error_should_be_not_initialized()
{
    // Arrange
    FakeBatteryDriver fakeBatteryDriver;
    BatterySensor batterySensor(fakeBatteryDriver);
    
    fakeBatteryDriver.currentDriverVoltage = BatteryConstants::BATTERY_VOLTAGE_MEASUREMENT_ERROR;

    // Act
    BatteryLevel batteryLevel = batterySensor.getBatteryLevel();

    // Assert
    TEST_ASSERT_EQUAL_UINT8(BatteryConstants::BATTERY_LEVEL_NOT_INITIALIZED, batteryLevel);
}

void test_battery_voltage_empty_should_be_battery_level_min()
{
    // Arrange
    FakeBatteryDriver fakeBatteryDriver;
    BatterySensor batterySensor(fakeBatteryDriver);
    
    fakeBatteryDriver.currentDriverVoltage = BatteryConstants::BATTERY_VOLTAGE_EMPTY;

    // Act
    BatteryLevel batteryLevel = batterySensor.getBatteryLevel();

    // Assert
    TEST_ASSERT_EQUAL_UINT8(BatteryConstants::BATTERY_LEVEL_MIN, batteryLevel);
}

void test_battery_voltage_full_should_be_battery_level_max()
{
    // Arrange
    FakeBatteryDriver fakeBatteryDriver;
    BatterySensor batterySensor(fakeBatteryDriver);
    
    fakeBatteryDriver.currentDriverVoltage = BatteryConstants::BATTERY_VOLTAGE_FULL;

    // Act
    BatteryLevel batteryLevel = batterySensor.getBatteryLevel();

    // Assert
    TEST_ASSERT_EQUAL_UINT8(BatteryConstants::BATTERY_LEVEL_MAX, batteryLevel);
}

void test_battery_voltage_middle_should_be_battery_level_50_percent()
{
    // Arrange
    FakeBatteryDriver fakeBatteryDriver;
    BatterySensor batterySensor(fakeBatteryDriver);
    
    fakeBatteryDriver.currentDriverVoltage = 3.6f;

    // Act
    BatteryLevel batteryLevel = batterySensor.getBatteryLevel();

    // Assert
    TEST_ASSERT_EQUAL_UINT8(50, batteryLevel);
}

void test_battery_voltage_below_empty_should_be_battery_level_min()
{
    // Arrange
    FakeBatteryDriver fakeBatteryDriver;
    BatterySensor batterySensor(fakeBatteryDriver);
    
    fakeBatteryDriver.currentDriverVoltage = BatteryConstants::BATTERY_VOLTAGE_EMPTY - 0.1f;

    // Act
    BatteryLevel batteryLevel = batterySensor.getBatteryLevel();

    // Assert
    TEST_ASSERT_EQUAL_UINT8(BatteryConstants::BATTERY_LEVEL_MIN, batteryLevel);
}

void test_battery_voltage_above_full_should_be_battery_level_max()
{
    // Arrange
    FakeBatteryDriver fakeBatteryDriver;
    BatterySensor batterySensor(fakeBatteryDriver);
    
    fakeBatteryDriver.currentDriverVoltage = BatteryConstants::BATTERY_VOLTAGE_FULL + 0.1f;

    // Act
    BatteryLevel batteryLevel = batterySensor.getBatteryLevel();

    // Assert
    TEST_ASSERT_EQUAL_UINT8(BatteryConstants::BATTERY_LEVEL_MAX, batteryLevel);
}