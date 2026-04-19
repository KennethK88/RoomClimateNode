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
void test_co_sensor_initialized_value_should_be_dummy_value();

int main() {
    UNITY_BEGIN();

    // COSensor
    RUN_TEST(test_co_sensor_not_initialized_value_should_be_not_initialized);
    RUN_TEST(test_co_sensor_initialized_value_should_be_dummy_value);

    return UNITY_END();
}