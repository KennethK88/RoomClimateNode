#include <unity.h>
#include <SensorCoordinator.h>
#include <CommonSensorConstants.h>

namespace
{
    const float epsilon = 0.1f;

    class FakeSensorDriver : public ISht31SensorDriver
    {
        public:
            Temperature currentDriverTemperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
            Humidity currentDriverHumidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;
            void init() override {}
            void readMeasurements() override {}
            Temperature getTemperature() override {return currentDriverTemperature;}
            Humidity getHumidity() override {return currentDriverHumidity;}
    };
}

void test_read_all_sensors_should_propagate_driver_values_to_measurements()
{

// Arrange
FakeSensorDriver fakeSensorDriver;
TemperatureSensor temperatureSensor(fakeSensorDriver);
HumiditySensor humiditySensor(fakeSensorDriver);
SensorCoordinator sensorCoordinator(temperatureSensor, humiditySensor);

fakeSensorDriver.currentDriverTemperature = 20.0f;
fakeSensorDriver.currentDriverHumidity = 30.0f;

// Act
Measurements measurements = sensorCoordinator.readAllSensors();

// Assert
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverTemperature, measurements.temperature);
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverHumidity, measurements.humidity);
}

void test_read_all_sensors_should_propagate_updated_driver_values_to_measurements()
{

// Arrange
FakeSensorDriver fakeSensorDriver;
TemperatureSensor temperatureSensor(fakeSensorDriver);
HumiditySensor humiditySensor(fakeSensorDriver);
SensorCoordinator sensorCoordinator(temperatureSensor, humiditySensor);

fakeSensorDriver.currentDriverTemperature = 20.0f;
fakeSensorDriver.currentDriverHumidity = 30.0f;

// Act
Measurements measurements = sensorCoordinator.readAllSensors();
fakeSensorDriver.currentDriverTemperature = 21.0f;
fakeSensorDriver.currentDriverHumidity = 35.0f;
measurements = sensorCoordinator.readAllSensors();

// Assert
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverTemperature, measurements.temperature);
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverHumidity, measurements.humidity);
}
