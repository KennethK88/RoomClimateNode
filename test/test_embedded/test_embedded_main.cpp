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
void test_thermistor_temperature_not_nan_should_be_true();
void test_thermistor_temperature_should_be_within_plausible_range();

// DistanceDriver
void test_distance_driver_distance_not_nan_should_be_true();
void test_distance_driver_distance_should_be_within_plausible_range();

void setup()
{  
    delay(5000);
    UNITY_BEGIN();

    // ThermistorDriver
    RUN_TEST(test_thermistor_temperature_not_nan_should_be_true);
    RUN_TEST(test_thermistor_temperature_should_be_within_plausible_range);

    // DistanceDriver
    RUN_TEST(test_distance_driver_distance_not_nan_should_be_true);
    RUN_TEST(test_distance_driver_distance_should_be_within_plausible_range);

    
    UNITY_END();
}

void loop()
{
    //
}