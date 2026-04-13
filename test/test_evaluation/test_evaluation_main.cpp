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

// All Sensors
void test_all_sensors_not_initialized_should_be_invalid();
void test_all_sensors_valid_values_should_be_valid();

// Temperature
void test_temperature_not_initialized_should_be_invalid();
void test_temperature_equals_max_valid_should_be_valid();
void test_temperature_equals_min_valid_should_be_valid();
void test_temperature_below_min_valid_should_be_invalid();
void test_temperature_above_max_valid_should_be_invalid();

// Humidity
void test_humidity_not_initialized_should_be_invalid();
void test_humidity_equals_max_valid_should_be_valid();
void test_humidity_equals_min_valid_should_be_valid();
void test_humidity_below_min_valid_should_be_invalid();
void test_humidity_above_max_valid_should_be_invalid();

// CO
void test_co_not_initialized_should_be_invalid();
void test_co_equals_max_valid_should_be_valid();
void test_co_equals_min_valid_should_be_valid();
void test_co_below_min_valid_should_be_invalid();
void test_co_above_max_valid_should_be_invalid();

int main() {
    UNITY_BEGIN();

    // All Sensors
    RUN_TEST(test_all_sensors_not_initialized_should_be_invalid);
    RUN_TEST(test_all_sensors_valid_values_should_be_valid);

    // Temperature
    RUN_TEST(test_temperature_not_initialized_should_be_invalid);
    RUN_TEST(test_temperature_equals_max_valid_should_be_valid);
    RUN_TEST(test_temperature_equals_min_valid_should_be_valid);
    RUN_TEST(test_temperature_below_min_valid_should_be_invalid);
    RUN_TEST(test_humidity_above_max_valid_should_be_invalid);

    // Humidity
    RUN_TEST(test_humidity_not_initialized_should_be_invalid);
    RUN_TEST(test_humidity_equals_max_valid_should_be_valid);
    RUN_TEST(test_humidity_equals_min_valid_should_be_valid);
    RUN_TEST(test_humidity_below_min_valid_should_be_invalid);
    RUN_TEST(test_humidity_above_max_valid_should_be_invalid);

    // CO
    RUN_TEST(test_co_not_initialized_should_be_invalid);
    RUN_TEST(test_co_equals_max_valid_should_be_valid);
    RUN_TEST(test_co_equals_min_valid_should_be_valid);
    RUN_TEST(test_co_below_min_valid_should_be_invalid);
    RUN_TEST(test_co_above_max_valid_should_be_invalid);

    return UNITY_END();
}