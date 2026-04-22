#include <unity.h>
#include <TemperatureSensor.h>
#include <ISensorDriver.h>

const float epsilon = 0.1f;

class FakeSensorDriver : public ISensorDriver
{
    public:
        float currentDriverValue = 0.0f;
        void init() override {}
        float getValue() override {return currentDriverValue;}
};

void test_temperature_sensor_not_initialized_value_should_be_not_initialized()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    TemperatureSensor temperatureSensor(fakeSensorDriver);

    // Act
    float temperatureValue = temperatureSensor.getTemperature();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, SensorConstants::TEMPERATURE_NOT_INITIALIZED, temperatureValue);
}

void test_temperature_sensor_initialized_value_should_be_equal_to_driver_value()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    TemperatureSensor temperatureSensor(fakeSensorDriver);
    
    fakeSensorDriver.currentDriverValue = 20.0f;

    // Act
    temperatureSensor.readTemperature();
    float temperatureValue = temperatureSensor.getTemperature();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverValue, temperatureValue);
}

void test_temperature_sensor_initialized_value_changes_should_be_equal_to_driver_value()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    TemperatureSensor temperatureSensor(fakeSensorDriver);
    
    fakeSensorDriver.currentDriverValue = 20.0f;

    // Act
    temperatureSensor.readTemperature();
    fakeSensorDriver.currentDriverValue = 30.0f;
    temperatureSensor.readTemperature();
    float temperatureValue = temperatureSensor.getTemperature();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverValue, temperatureValue);
}