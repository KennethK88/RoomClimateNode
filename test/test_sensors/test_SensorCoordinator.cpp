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

class FakeSensorDriverCO : public ISensorDriver
{
    public:
        float currentDriverCO = 50.0f;
        void init() override {}
        float getValue() override {return currentDriverCO;}
};

class FakeSensorDriverDistance : public ISensorDriver
{
    public:
        float currentDriverDistance = 40.0f;
        void init() override {}
        float getValue() override {return currentDriverDistance;}
};


void test_read_all_sensors_should_propagate_driver_values_to_measurements()
{

// Arrange
FakeSensorDriverTemperature fakeSensorDriverTemperature;
FakeSensorDriverHumidity fakeSensorDriverHumidity;
FakeSensorDriverCO fakeSensorDriverCO;
FakeSensorDriverDistance fakeSensorDriverDistance;

TemperatureSensor temperatureSensor(fakeSensorDriverTemperature);
HumiditySensor humiditySensor(fakeSensorDriverHumidity);
COSensor coSensor(fakeSensorDriverCO);
DistanceSensor distanceSensor(fakeSensorDriverDistance);

SensorCoordinator sensorCoordinator(temperatureSensor, humiditySensor, coSensor, distanceSensor);

// Act
Measurements measurements = sensorCoordinator.readAllSensors();

// Assert
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriverTemperature.currentDriverTemperature, measurements.temperature);
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriverHumidity.currentDriverHumidity, measurements.humidity);
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriverCO.currentDriverCO, measurements.co);
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriverDistance.currentDriverDistance, measurements.distance);
}

void test_read_all_sensors_should_propagate_updated_driver_values_to_measurements()
{

// Arrange
FakeSensorDriverTemperature fakeSensorDriverTemperature;
FakeSensorDriverHumidity fakeSensorDriverHumidity;
FakeSensorDriverCO fakeSensorDriverCO;
FakeSensorDriverDistance fakeSensorDriverDistance;

TemperatureSensor temperatureSensor(fakeSensorDriverTemperature);
HumiditySensor humiditySensor(fakeSensorDriverHumidity);
COSensor coSensor(fakeSensorDriverCO);
DistanceSensor distanceSensor(fakeSensorDriverDistance);

SensorCoordinator sensorCoordinator(temperatureSensor, humiditySensor, coSensor, distanceSensor);

// Act
Measurements measurements = sensorCoordinator.readAllSensors();
fakeSensorDriverTemperature.currentDriverTemperature = 21.0f;
fakeSensorDriverHumidity.currentDriverHumidity = 35.0f;
fakeSensorDriverCO.currentDriverCO = 100.0f;
fakeSensorDriverDistance.currentDriverDistance = 70.0f;
measurements = sensorCoordinator.readAllSensors();

// Assert
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriverTemperature.currentDriverTemperature, measurements.temperature);
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriverHumidity.currentDriverHumidity, measurements.humidity);
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriverCO.currentDriverCO, measurements.co);
TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriverDistance.currentDriverDistance, measurements.distance);
}
