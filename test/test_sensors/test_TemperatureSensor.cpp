#include <unity.h>
#include <TemperatureSensor.h>
#include <ISht31SensorDriver.h>
#include <CommonSensorConstants.h>

namespace
{
    const float epsilon = 0.1f;

    class FakeSensorDriver : public ISht31SensorDriver
    {
        public:
            Temperature currentDriverTemperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
            void init() override {}
            void readMeasurements() override {}
            Temperature getTemperature() override {return currentDriverTemperature;}
            Humidity getHumidity() override {return 0;}
    };
}

void test_temperature_sensor_not_initialized_value_should_be_not_initialized()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    TemperatureSensor temperatureSensor(fakeSensorDriver);

    // Act
    Temperature temperatureValue = temperatureSensor.getTemperature();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, SensorConstants::TEMPERATURE_NOT_INITIALIZED, temperatureValue);
}

void test_temperature_sensor_initialized_value_should_be_equal_to_driver_value()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    TemperatureSensor temperatureSensor(fakeSensorDriver);
    
    fakeSensorDriver.currentDriverTemperature = 20.0f;

    // Act
    Temperature temperatureValue = temperatureSensor.getTemperature();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverTemperature, temperatureValue);
}

void test_temperature_sensor_initialized_value_changes_should_be_equal_to_driver_value()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    TemperatureSensor temperatureSensor(fakeSensorDriver);
    
    fakeSensorDriver.currentDriverTemperature = 20.0f;

    // Act
    fakeSensorDriver.currentDriverTemperature = 30.0f;
    Temperature temperatureValue = temperatureSensor.getTemperature();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverTemperature, temperatureValue);
}