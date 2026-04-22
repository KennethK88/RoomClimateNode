#include <unity.h>
#include <HumiditySensor.h>
#include <ISensorDriver.h>

const float epsilon = 0.1f;

class FakeSensorDriver : public ISensorDriver
{
    public:
        float currentDriverValue = 0.0f;
        void init() override {}
        float getValue() override {return currentDriverValue;}
};

void test_humidity_sensor_not_initialized_value_should_be_not_initialized()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    HumiditySensor humiditySensor(fakeSensorDriver);

    // Act
    float humidityValue = humiditySensor.getHumidity();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, SensorConstants::HUMIDITY_NOT_INITIALIZED, humidityValue);
}

void test_humidity_sensor_initialized_value_should_be_equal_to_driver_value()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    HumiditySensor humiditySensor(fakeSensorDriver);
    
    fakeSensorDriver.currentDriverValue = 20.0f;

    // Act
    humiditySensor.readHumidity();
    float humidityValue = humiditySensor.getHumidity();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverValue, humidityValue);
}

void test_humidity_sensor_initialized_value_changes_should_be_equal_to_driver_value()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    HumiditySensor humiditySensor(fakeSensorDriver);
    
    fakeSensorDriver.currentDriverValue = 20.0f;

    // Act
    humiditySensor.readHumidity();
    fakeSensorDriver.currentDriverValue = 30.0f;
    humiditySensor.readHumidity();
    float humidityValue = humiditySensor.getHumidity();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverValue, humidityValue);
}