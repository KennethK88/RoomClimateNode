#include <unity.h>
#include <COSensor.h>
#include <ISensorDriver.h>

const float epsilon = 0.1f;

class FakeSensorDriver : public ISensorDriver
{
    public:
        float currentDriverValue = 0.0f;
        void init() override {}
        float getValue() override {return currentDriverValue;}
};

void test_co_sensor_not_initialized_value_should_be_not_initialized()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    COSensor coSensor(fakeSensorDriver);

    // Act
    float coValue = coSensor.getCO();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, SensorConstants::CO_NOT_INITIALIZED, coValue);
}

void test_co_sensor_initialized_value_should_be_equal_to_driver_value()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    COSensor coSensor(fakeSensorDriver);
    
    fakeSensorDriver.currentDriverValue = 20.0f;

    // Act
    coSensor.readCO();
    float coValue = coSensor.getCO();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverValue, coValue);
}

void test_co_sensor_initialized_value_changes_should_be_equal_to_driver_value()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    COSensor coSensor(fakeSensorDriver);
    
    fakeSensorDriver.currentDriverValue = 20.0f;

    // Act
    coSensor.readCO();
    fakeSensorDriver.currentDriverValue = 30.0f;
    coSensor.readCO();
    float coValue = coSensor.getCO();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverValue, coValue);
}