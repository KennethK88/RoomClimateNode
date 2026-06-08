#include <unity.h>
#include <HumiditySensor.h>
#include <ISht31SensorDriver.h>

namespace
{
    const float epsilon = 0.1f;

    class FakeSensorDriver : public ISht31SensorDriver
    {
        public:
            Humidity currentDriverHumidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;
            void init() override {}
            void readMeasurements() override {}
            Temperature getTemperature() override {}
            Humidity getHumidity() override {return currentDriverHumidity;}
    };
}

void test_humidity_sensor_not_initialized_value_should_be_not_initialized()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    HumiditySensor humiditySensor(fakeSensorDriver);

    // Act
    Humidity humidityValue = humiditySensor.getHumidity();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, SensorConstants::HUMIDITY_NOT_INITIALIZED, humidityValue);
}

void test_humidity_sensor_initialized_value_should_be_equal_to_driver_value()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    HumiditySensor humiditySensor(fakeSensorDriver);
    
    fakeSensorDriver.currentDriverHumidity = 20.0f;

    // Act
    Humidity humidityValue = humiditySensor.getHumidity();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverHumidity, humidityValue);
}

void test_humidity_sensor_initialized_value_changes_should_be_equal_to_driver_value()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    HumiditySensor humiditySensor(fakeSensorDriver);
    
    fakeSensorDriver.currentDriverHumidity = 20.0f;

    // Act
    fakeSensorDriver.currentDriverHumidity = 30.0f;
    Humidity humidityValue = humiditySensor.getHumidity();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverHumidity, humidityValue);
}