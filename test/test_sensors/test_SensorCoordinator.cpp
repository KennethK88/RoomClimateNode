#include <unity.h>
#include <TemperatureSensor.h>
#include <HumiditySensor.h>
#include <BatterySensor.h>
#include <ISht31SensorDriver.h>
#include <IBatteryDriver.h>
#include <SensorCoordinator.h>
#include <CommonSensorConstants.h>
#include <BatteryConstants.h>

namespace
{
    constexpr float epsilon = 0.1f;

    class FakeSht31Driver : public ISht31SensorDriver
    {
        public:
            Temperature currentDriverTemperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
            Humidity currentDriverHumidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;
            void init() override {}
            void readMeasurements() override {}
            Temperature getTemperature() override {return currentDriverTemperature;}
            Humidity getHumidity() override {return currentDriverHumidity;}
    };

    class FakeBatteryDriver : public IBatteryDriver
    {
        public:
            BatteryVoltage currentDriverVoltage = BatteryConstants::BATTERY_VOLTAGE_NOT_INITIALIZED;
            void init() override {}
            void readVoltage() override {}
            BatteryVoltage getVoltage() const override {return currentDriverVoltage;}
    };
}

void test_read_all_sensors_should_store_sensor_values_in_measurements()
{
    // Arrange
    FakeSht31Driver fakeSht31Driver;
    FakeBatteryDriver fakeBatteryDriver;
    TemperatureSensor temperatureSensor(fakeSht31Driver);
    HumiditySensor humiditySensor(fakeSht31Driver);
    BatterySensor batterySensor(fakeBatteryDriver);
    SensorCoordinator sensorCoordinator(temperatureSensor, humiditySensor, batterySensor);

    fakeSht31Driver.currentDriverTemperature = 20.0f;
    fakeSht31Driver.currentDriverHumidity = 30.0f;
    fakeBatteryDriver.currentDriverVoltage = 3.6f;

    // Act
    Measurements measurements = sensorCoordinator.readAllSensors();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSht31Driver.currentDriverTemperature, measurements.temperature);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSht31Driver.currentDriverHumidity, measurements.humidity);
    TEST_ASSERT_EQUAL_UINT8(50, measurements.batteryLevel);
}

void test_read_all_sensors_should_store_updated_sensor_values_in_measurements()
{
    // Arrange
    FakeSht31Driver fakeSht31Driver;
    FakeBatteryDriver fakeBatteryDriver;
    TemperatureSensor temperatureSensor(fakeSht31Driver);
    HumiditySensor humiditySensor(fakeSht31Driver);
    BatterySensor batterySensor(fakeBatteryDriver);
    SensorCoordinator sensorCoordinator(temperatureSensor, humiditySensor, batterySensor);

    fakeSht31Driver.currentDriverTemperature = 20.0f;
    fakeSht31Driver.currentDriverHumidity = 30.0f;
    fakeBatteryDriver.currentDriverVoltage = 3.6f;

    // Act
    Measurements measurements = sensorCoordinator.readAllSensors();
    fakeSht31Driver.currentDriverTemperature = 21.0f;
    fakeSht31Driver.currentDriverHumidity = 35.0f;
    fakeBatteryDriver.currentDriverVoltage = 3.5f;
    measurements = sensorCoordinator.readAllSensors();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSht31Driver.currentDriverTemperature, measurements.temperature);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, fakeSht31Driver.currentDriverHumidity, measurements.humidity);
    TEST_ASSERT_EQUAL_UINT8(42, measurements.batteryLevel);
}
