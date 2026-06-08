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

// SensorValidator
// All Sensors
void test_all_sensors_not_initialized_should_be_invalid();
void test_all_sensors_valid_values_should_be_valid();

// Temperature
void test_temperature_not_initialized_should_be_invalid();
void test_temperature_equals_max_valid_should_be_valid();
void test_temperature_equals_min_valid_should_be_valid();
void test_temperature_equals_nan_should_be_invalid();
void test_temperature_below_min_valid_should_be_invalid();
void test_temperature_above_max_valid_should_be_invalid();

// Humidity
void test_humidity_not_initialized_should_be_invalid();
void test_humidity_equals_max_valid_should_be_valid();
void test_humidity_equals_min_valid_should_be_valid();
void test_humidity_equals_nan_should_be_invalid();
void test_humidity_below_min_valid_should_be_invalid();
void test_humidity_above_max_valid_should_be_invalid();

// StateMachine
void test_all_validations_valid_and_all_thresholds_ok_state_should_be_normal();
void test_temperature_invalid_and_all_thresholds_ok_state_should_be_error();
void test_humidity_invalid_and_all_thresholds_ok_state_should_be_error();


int main() {
    UNITY_BEGIN();

    // SensorValidator
    // All Sensors
    RUN_TEST(test_all_sensors_not_initialized_should_be_invalid);
    RUN_TEST(test_all_sensors_valid_values_should_be_valid);

    // Temperature
    RUN_TEST(test_temperature_not_initialized_should_be_invalid);
    RUN_TEST(test_temperature_equals_max_valid_should_be_valid);
    RUN_TEST(test_temperature_equals_min_valid_should_be_valid);
    RUN_TEST(test_temperature_equals_nan_should_be_invalid);
    RUN_TEST(test_temperature_below_min_valid_should_be_invalid);
    RUN_TEST(test_temperature_above_max_valid_should_be_invalid);

    // Humidity
    RUN_TEST(test_humidity_not_initialized_should_be_invalid);
    RUN_TEST(test_humidity_equals_max_valid_should_be_valid);
    RUN_TEST(test_humidity_equals_min_valid_should_be_valid);
    RUN_TEST(test_humidity_equals_nan_should_be_invalid);
    RUN_TEST(test_humidity_below_min_valid_should_be_invalid);
    RUN_TEST(test_humidity_above_max_valid_should_be_invalid);

    // StateMachine
    RUN_TEST(test_all_validations_valid_and_all_thresholds_ok_state_should_be_normal);
    RUN_TEST(test_temperature_invalid_and_all_thresholds_ok_state_should_be_error);
    RUN_TEST(test_humidity_invalid_and_all_thresholds_ok_state_should_be_error);

    return UNITY_END();
}