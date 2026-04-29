#include <Arduino.h> 
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
// void test_thermistor_temperature_not_nan_should_be_true();
// void test_thermistor_temperature_should_be_within_plausible_range();

void test_calculator_addition() {
    TEST_ASSERT_EQUAL(32, 32);
}

void setup()
{  
    //Serial.begin(115200);
    delay(2000);
    //while (!Serial) { /* warten bis Serial Monitor geöffnet */};

    UNITY_BEGIN();

    // ThermistorDriver
    // RUN_TEST(test_thermistor_temperature_not_nan_should_be_true);
    // RUN_TEST(test_thermistor_temperature_should_be_within_plausible_range);
    RUN_TEST(test_calculator_addition);

    UNITY_END();
}

void loop()
{
    //
}