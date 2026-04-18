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

// AlarmController
void test_state_is_normal_alarm_should_be_inactive();
void test_state_is_error_alarm_should_be_inactive();
void test_state_is_warning_alarm_should_be_active();

int main() {
    UNITY_BEGIN();

    // AlarmController
    RUN_TEST(test_state_is_normal_alarm_should_be_inactive);
    RUN_TEST(test_state_is_error_alarm_should_be_inactive);
    RUN_TEST(test_state_is_warning_alarm_should_be_active);

    return UNITY_END();
}