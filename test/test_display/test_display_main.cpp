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

// DisplayController
void test_display_current_values_and_state_normal_should_display_four_lines();
void test_display_current_values_rounded_and_state_normal_should_display_four_lines();
void test_display_current_values_and_state_warning_should_display_four_lines();
void test_display_current_values_and_state_error_should_display_four_lines();
void test_update_display_should_enter_sleep_mode_when_display_inactive();

// DisplayPolicy
void test_distance_invalid_display_should_be_active();
void test_distance_valid_and_value_equals_on_off_threshold_display_should_be_active();
void test_distance_valid_and_value_below_on_off_threshold_display_should_be_active();
void test_distance_valid_and_value_above_on_off_threshold_display_should_be_inactive();
void test_distance_valid_no_object_detected_display_should_be_inactive();
void test_distance_invalid_no_object_detected_display_should_be_active();

int main() {
    UNITY_BEGIN();

    // DisplayController
    RUN_TEST(test_display_current_values_and_state_normal_should_display_four_lines);
    RUN_TEST(test_display_current_values_rounded_and_state_normal_should_display_four_lines);
    RUN_TEST(test_display_current_values_and_state_warning_should_display_four_lines);
    RUN_TEST(test_display_current_values_and_state_error_should_display_four_lines);
    RUN_TEST(test_update_display_should_enter_sleep_mode_when_display_inactive);

    // DisplayPolicy
    RUN_TEST(test_distance_invalid_display_should_be_active);
    RUN_TEST(test_distance_valid_and_value_equals_on_off_threshold_display_should_be_active);
    RUN_TEST(test_distance_valid_and_value_below_on_off_threshold_display_should_be_active);
    RUN_TEST(test_distance_valid_and_value_above_on_off_threshold_display_should_be_inactive);
    RUN_TEST(test_distance_valid_no_object_detected_display_should_be_inactive);
    RUN_TEST(test_distance_invalid_no_object_detected_display_should_be_active);

    return UNITY_END();
}