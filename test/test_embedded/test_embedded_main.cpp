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

// SHT31Driver
void test_sht31_driver_should_measure_room_temperature_range();
void test_sht31_driver_should_measure_room_humidity_range();

void setup()
{  
    delay(10000); // NOTE: Großes Delay
    UNITY_BEGIN();

    // ThermistorDriver
    RUN_TEST(test_sht31_driver_should_measure_room_temperature_range);

    // HumidityDriver
    RUN_TEST(test_sht31_driver_should_measure_room_humidity_range);
    
    UNITY_END();
}

void loop()
{
    //
}