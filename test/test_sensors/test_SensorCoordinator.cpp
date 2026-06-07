#include <unity.h>
#include <SensorCoordinator.h>

const float epsilon = 0.1f;

class FakeSensorDriverTemperature : public ISensorDriver
{
    public:
        float currentDriverTemperature = 20.0f;
        void init() override {}
        float getValue() override {return currentDriverTemperature;}
};

class FakeSensorDriverHumidity : public ISensorDriver
{
    public:
        float currentDriverHumidity = 30.0f;
        void init() override {}
        float getValue() override {return currentDriverHumidity;}
};

void test_read_all_sensors_should_propagate_driver_values_to_measurements()
{

// Arrange
FakeSensorDriverTemperature fakeSensorDriverTemperature;
FakeSensorDriverHumidity fakeSensorDriverHumidity;

TemperatureSensor temperatureSensor(fakeSensorDriverTemperature);
HumiditySensor humiditySensor(fakeSensorDriverHumidity);

SensorCoordinator sensorCoordinator(temperatureSensor, humiditySensor);

// Act
Measurements measurements = sensorCoordinator.readAllSensors();

// Assert
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriverTemperature.currentDriverTemperature, measurements.temperature);
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriverHumidity.currentDriverHumidity, measurements.humidity);
}

void test_read_all_sensors_should_propagate_updated_driver_values_to_measurements()
{

// Arrange
FakeSensorDriverTemperature fakeSensorDriverTemperature;
FakeSensorDriverHumidity fakeSensorDriverHumidity;

TemperatureSensor temperatureSensor(fakeSensorDriverTemperature);
HumiditySensor humiditySensor(fakeSensorDriverHumidity);

SensorCoordinator sensorCoordinator(temperatureSensor, humiditySensor);

// Act
Measurements measurements = sensorCoordinator.readAllSensors();
fakeSensorDriverTemperature.currentDriverTemperature = 21.0f;
fakeSensorDriverHumidity.currentDriverHumidity = 35.0f;
measurements = sensorCoordinator.readAllSensors();

// Assert
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriverTemperature.currentDriverTemperature, measurements.temperature);
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriverHumidity.currentDriverHumidity, measurements.humidity);
}
