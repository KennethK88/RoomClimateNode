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

int main() {
    UNITY_BEGIN();

    // DisplayController
    RUN_TEST(test_display_current_values_and_state_normal_should_display_four_lines);
    RUN_TEST(test_display_current_values_rounded_and_state_normal_should_display_four_lines);
    RUN_TEST(test_display_current_values_and_state_warning_should_display_four_lines);
    RUN_TEST(test_display_current_values_and_state_error_should_display_four_lines);

    return UNITY_END();
}