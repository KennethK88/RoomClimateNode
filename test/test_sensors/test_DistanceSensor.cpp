#include <unity.h>
#include <DistanceSensor.h>
#include <ISensorDriver.h>

const float epsilon = 0.1f;

class FakeSensorDriver : public ISensorDriver
{
    public:
        float currentDriverValue = 0.0f;
        void init() override {}
        float getValue() override {return currentDriverValue;}
};

void test_distance_sensor_not_initialized_value_should_be_not_initialized()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    DistanceSensor distanceSensor(fakeSensorDriver);

    // Act
    float distanceValue = distanceSensor.getDistance();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, SensorConstants::DISTANCE_NOT_INITIALIZED, distanceValue);
}

void test_distance_sensor_initialized_value_should_be_equal_to_driver_value()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    DistanceSensor distanceSensor(fakeSensorDriver);
    
    fakeSensorDriver.currentDriverValue = 20.0f;

    // Act
    distanceSensor.readDistance();
    float distanceValue = distanceSensor.getDistance();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverValue, distanceValue);
}

void test_distance_sensor_initialized_value_changes_should_be_equal_to_driver_value()
{
    // Arrange
    FakeSensorDriver fakeSensorDriver;
    DistanceSensor distanceSensor(fakeSensorDriver);
    
    fakeSensorDriver.currentDriverValue = 20.0f;

    // Act
    distanceSensor.readDistance();
    fakeSensorDriver.currentDriverValue = 30.0f;
    distanceSensor.readDistance();
    float distanceValue = distanceSensor.getDistance();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSensorDriver.currentDriverValue, distanceValue);
}