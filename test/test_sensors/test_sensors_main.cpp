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

// TemperatureSensor
void test_temperature_sensor_not_initialized_value_should_be_not_initialized();
void test_temperature_sensor_initialized_value_should_be_equal_to_driver_value();
void test_temperature_sensor_initialized_value_changes_should_be_equal_to_driver_value();

// HumiditySensor
void test_humidity_sensor_not_initialized_value_should_be_not_initialized();
void test_humidity_sensor_initialized_value_should_be_equal_to_driver_value();
void test_humidity_sensor_initialized_value_changes_should_be_equal_to_driver_value();

// BatterySensor
void test_battery_voltage_not_initialized_should_be_not_initialized();
void test_battery_voltage_measurement_error_should_be_not_initialized();
void test_battery_voltage_empty_should_be_battery_level_min();
void test_battery_voltage_full_should_be_battery_level_max();
void test_battery_voltage_middle_should_be_battery_level_50_percent();
void test_battery_voltage_below_empty_should_be_battery_level_min();
void test_battery_voltage_above_full_should_be_battery_level_max();

// SensorCoordinator
void test_read_all_sensors_should_store_sensor_values_in_measurements();
void test_read_all_sensors_should_store_updated_sensor_values_in_measurements();

int main()
{
    UNITY_BEGIN();

    // TemperatureSensor
    RUN_TEST(test_temperature_sensor_not_initialized_value_should_be_not_initialized);
    RUN_TEST(test_temperature_sensor_initialized_value_should_be_equal_to_driver_value);
    RUN_TEST(test_temperature_sensor_initialized_value_changes_should_be_equal_to_driver_value);

    // HumiditySensor
    RUN_TEST(test_humidity_sensor_not_initialized_value_should_be_not_initialized);
    RUN_TEST(test_humidity_sensor_initialized_value_should_be_equal_to_driver_value);
    RUN_TEST(test_humidity_sensor_initialized_value_changes_should_be_equal_to_driver_value);

    // BatterySensor
    RUN_TEST(test_battery_voltage_not_initialized_should_be_not_initialized);
    RUN_TEST(test_battery_voltage_measurement_error_should_be_not_initialized);
    RUN_TEST(test_battery_voltage_empty_should_be_battery_level_min);
    RUN_TEST(test_battery_voltage_full_should_be_battery_level_max);
    RUN_TEST(test_battery_voltage_middle_should_be_battery_level_50_percent);
    RUN_TEST(test_battery_voltage_below_empty_should_be_battery_level_min);
    RUN_TEST(test_battery_voltage_above_full_should_be_battery_level_max);

    // Sensor Coordinator
    RUN_TEST(test_read_all_sensors_should_store_sensor_values_in_measurements);
    RUN_TEST(test_read_all_sensors_should_store_updated_sensor_values_in_measurements);    
    
    return UNITY_END();
}