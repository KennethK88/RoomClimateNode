#include <unity.h>

// Wird vor JEDEM Test aufgerufen
void setUp()
{

}

// Wird nach JEDEM Test aufgerufen
void tearDown()
{
    // Hier könntest du aufräumen
}

// COSensor
void test_co_sensor_not_initialized_value_should_be_not_initialized();
void test_co_sensor_initialized_value_should_be_equal_to_driver_value();
void test_co_sensor_initialized_value_changes_should_be_equal_to_driver_value();

// TemperatureSensor
void test_temperature_sensor_not_initialized_value_should_be_not_initialized();
void test_temperature_sensor_initialized_value_should_be_equal_to_driver_value();
void test_temperature_sensor_initialized_value_changes_should_be_equal_to_driver_value();

// HumiditySensor
void test_humidity_sensor_not_initialized_value_should_be_not_initialized();
void test_humidity_sensor_initialized_value_should_be_equal_to_driver_value();
void test_humidity_sensor_initialized_value_changes_should_be_equal_to_driver_value();

// DistanceSensor
void test_distance_sensor_not_initialized_value_should_be_not_initialized();
void test_distance_sensor_initialized_value_should_be_equal_to_driver_value();
void test_distance_sensor_initialized_value_changes_should_be_equal_to_driver_value();// SensorCoordinator
void test_read_all_sensors_should_propagate_driver_values_to_measurements();
void test_read_all_sensors_should_propagate_updated_driver_values_to_measurements();int main() {
    UNITY_BEGIN();

    // COSensor
    RUN_TEST(test_co_sensor_not_initialized_value_should_be_not_initialized);
    RUN_TEST(test_co_sensor_initialized_value_should_be_equal_to_driver_value);
    RUN_TEST(test_co_sensor_initialized_value_changes_should_be_equal_to_driver_value);

    // TemperatureSensor
    RUN_TEST(test_temperature_sensor_not_initialized_value_should_be_not_initialized);
    RUN_TEST(test_temperature_sensor_initialized_value_should_be_equal_to_driver_value);
    RUN_TEST(test_temperature_sensor_initialized_value_changes_should_be_equal_to_driver_value);

    // HumiditySensor
    RUN_TEST(test_humidity_sensor_not_initialized_value_should_be_not_initialized);
    RUN_TEST(test_humidity_sensor_initialized_value_should_be_equal_to_driver_value);
    RUN_TEST(test_humidity_sensor_initialized_value_changes_should_be_equal_to_driver_value);

    // DistanceSensor
    RUN_TEST(test_distance_sensor_not_initialized_value_should_be_not_initialized);
    RUN_TEST(test_distance_sensor_initialized_value_should_be_equal_to_driver_value);
    RUN_TEST(test_distance_sensor_initialized_value_changes_should_be_equal_to_driver_value);
    // Sensor Coordinator
    RUN_TEST(test_read_all_sensors_should_propagate_driver_values_to_measurements);
    RUN_TEST(test_read_all_sensors_should_propagate_updated_driver_values_to_measurements);    return UNITY_END();
}