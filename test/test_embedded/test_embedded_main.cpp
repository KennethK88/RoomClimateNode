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

// ThermistorDriver
//void test_thermistor_temperature_not_nan_should_be_true();
//void test_thermistor_temperature_top();



int main() {
    //delay(10000);
    UNITY_BEGIN();

    // ThermistorDriver
    //RUN_TEST(test_thermistor_temperature_top);
    TEST_ASSERT_TRUE(true);

    return UNITY_END();
}