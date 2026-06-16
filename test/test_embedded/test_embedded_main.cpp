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


// WiFiConnectionManager
void test_wifi_connection_manager_should_establish_wifi_connection();

// MqttClientService
void test_mqtt_client_service_should_establish_connection_to_broker();

// SHT31Driver
void test_sht31_driver_should_measure_room_temperature_range();
void test_sht31_driver_should_measure_room_humidity_range();

// ESP32BatteryDriver
void test_esp32_battery_driver_should_measure_battery_voltage_in_valid_range();

void setup()
{  
    delay(5000); // NOTE: Großes Delay
    UNITY_BEGIN();

    // WiFiConnectionManager
    RUN_TEST(test_wifi_connection_manager_should_establish_wifi_connection);

    // MqttClientService
    RUN_TEST(test_mqtt_client_service_should_establish_connection_to_broker);

    // SHT31Driver
    RUN_TEST(test_sht31_driver_should_measure_room_temperature_range);
    RUN_TEST(test_sht31_driver_should_measure_room_humidity_range);

    // ESP32BatteryDriver
    RUN_TEST(test_esp32_battery_driver_should_measure_battery_voltage_in_valid_range);

    UNITY_END();
}

void loop()
{
    //
}