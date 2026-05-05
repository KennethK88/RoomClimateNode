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
void test_thermistor_driver_should_measure_room_temperature_range();

// DistanceDriver
void test_distance_driver_should_measure_distance_with_object_present();

void setup()
{  
    delay(5000);
    UNITY_BEGIN();

    // ThermistorDriver
    RUN_TEST(test_thermistor_driver_should_measure_room_temperature_range);

    // DistanceDriver
    RUN_TEST(test_distance_driver_should_measure_distance_with_object_present);

    
    UNITY_END();
}

void loop()
{
    //
}