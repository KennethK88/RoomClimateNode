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

// CO
void test_co_not_initialized_should_be_invalid();
void test_co_equals_max_valid_should_be_valid();
void test_co_equals_min_valid_should_be_valid();
void test_co_equals_nan_should_be_invalid();
void test_co_below_min_valid_should_be_invalid();
void test_co_above_max_valid_should_be_invalid();

// ThresholdEvaluator
// Temperature
void test_temperature_valid_and_within_thresholds_should_not_trigger_any_threshold_flags();
void test_temperature_valid_and_equals_max_threshold_should_trigger_too_high_flag();
void test_temperature_valid_and_equals_min_threshold_should_trigger_too_low_flag();
void test_temperature_valid_and_below_min_threshold_should_trigger_too_low_flag();
void test_temperature_valid_and_above_max_threshold_should_trigger_too_high_flag();
void test_temperature_invalid_and_below_min_threshold_should_not_trigger_any_threshold_flags();
void test_temperature_invalid_and_above_max_threshold_should_not_trigger_any_threshold_flags();

// Humidity
void test_humidity_valid_and_within_thresholds_should_not_trigger_any_threshold_flags();
void test_humidity_valid_and_equals_max_threshold_should_trigger_too_high_flag();
void test_humidity_valid_and_equals_min_threshold_should_trigger_too_low_flag();
void test_humidity_valid_and_below_min_threshold_should_trigger_too_low_flag();
void test_humidity_valid_and_above_max_threshold_should_trigger_too_high_flag();
void test_humidity_invalid_and_below_min_threshold_should_not_trigger_any_threshold_flags();
void test_humidity_invalid_and_above_max_threshold_should_not_trigger_any_threshold_flags();

// CO
void test_co_valid_and_within_thresholds_should_not_trigger_any_threshold_flags();
void test_co_valid_and_equals_max_threshold_should_trigger_too_high_flag();
void test_co_valid_and_above_max_threshold_should_trigger_too_high_flag();
void test_co_invalid_and_above_max_threshold_should_not_trigger_any_threshold_flags();


// StateMachine
void test_all_validations_valid_and_all_thresholds_ok_state_should_be_normal();
void test_temperature_invalid_and_all_thresholds_ok_state_should_be_error();
void test_humidity_invalid_and_all_thresholds_ok_state_should_be_error();
void test_co_invalid_and_all_thresholds_ok_state_should_be_error();
void test_all_validations_valid_and_temperature_too_high_state_should_be_warning();
void test_all_validations_valid_and_temperature_too_low_state_should_be_warning();
void test_all_validations_valid_and_humidity_too_high_state_should_be_warning();
void test_all_validations_valid_and_humidity_too_low_state_should_be_warning();
void test_all_validations_valid_and_co_too_high_state_should_be_warning();

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

    // CO
    RUN_TEST(test_co_not_initialized_should_be_invalid);
    RUN_TEST(test_co_equals_max_valid_should_be_valid);
    RUN_TEST(test_co_equals_min_valid_should_be_valid);
    RUN_TEST(test_co_equals_nan_should_be_invalid);
    RUN_TEST(test_co_below_min_valid_should_be_invalid);
    RUN_TEST(test_co_above_max_valid_should_be_invalid);

    // ThresholdEvaluator
    // Temperature
    RUN_TEST(test_temperature_valid_and_within_thresholds_should_not_trigger_any_threshold_flags);
    RUN_TEST(test_temperature_valid_and_equals_max_threshold_should_trigger_too_high_flag);
    RUN_TEST(test_temperature_valid_and_equals_min_threshold_should_trigger_too_low_flag);
    RUN_TEST(test_temperature_valid_and_below_min_threshold_should_trigger_too_low_flag);
    RUN_TEST(test_temperature_valid_and_above_max_threshold_should_trigger_too_high_flag);
    RUN_TEST(test_temperature_invalid_and_below_min_threshold_should_not_trigger_any_threshold_flags);
    RUN_TEST(test_temperature_invalid_and_above_max_threshold_should_not_trigger_any_threshold_flags);

    // Humidity
    RUN_TEST(test_humidity_valid_and_within_thresholds_should_not_trigger_any_threshold_flags);
    RUN_TEST(test_humidity_valid_and_equals_max_threshold_should_trigger_too_high_flag);
    RUN_TEST(test_humidity_valid_and_equals_min_threshold_should_trigger_too_low_flag);
    RUN_TEST(test_humidity_valid_and_below_min_threshold_should_trigger_too_low_flag);
    RUN_TEST(test_humidity_valid_and_above_max_threshold_should_trigger_too_high_flag);
    RUN_TEST(test_humidity_invalid_and_below_min_threshold_should_not_trigger_any_threshold_flags);
    RUN_TEST(test_humidity_invalid_and_above_max_threshold_should_not_trigger_any_threshold_flags);
    
    // CO
    RUN_TEST(test_co_valid_and_within_thresholds_should_not_trigger_any_threshold_flags);
    RUN_TEST(test_co_valid_and_equals_max_threshold_should_trigger_too_high_flag);
    RUN_TEST(test_co_valid_and_above_max_threshold_should_trigger_too_high_flag);
    RUN_TEST(test_co_invalid_and_above_max_threshold_should_not_trigger_any_threshold_flags);

    // StateMachine
    RUN_TEST(test_all_validations_valid_and_all_thresholds_ok_state_should_be_normal);
    RUN_TEST(test_temperature_invalid_and_all_thresholds_ok_state_should_be_error);
    RUN_TEST(test_humidity_invalid_and_all_thresholds_ok_state_should_be_error);
    RUN_TEST(test_co_invalid_and_all_thresholds_ok_state_should_be_error);
    RUN_TEST(test_all_validations_valid_and_temperature_too_high_state_should_be_warning);
    RUN_TEST(test_all_validations_valid_and_temperature_too_low_state_should_be_warning);
    RUN_TEST(test_all_validations_valid_and_humidity_too_high_state_should_be_warning);
    RUN_TEST(test_all_validations_valid_and_humidity_too_low_state_should_be_warning);
    RUN_TEST(test_all_validations_valid_and_co_too_high_state_should_be_warning);

    return UNITY_END();
}