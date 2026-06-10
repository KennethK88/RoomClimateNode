#include <unity.h>
#include <MqttClientService.h>
#include <WiFiConnectionManager.h>
#include <Arduino.h>

void test_mqtt_client_service_should_establish_connection_to_broker()
{
    // NOTE: Dieser Test setzt WiFi Empfang samt korrekter Zugangsdaten sowie einen aktiven Mqtt Broker samt korrekter Zugangsdaten voraus.

    // Arrange
    WiFiConnectionManager wifiConnectionManager;
    MqttClientService mqttClientService;
    wifiConnectionManager.init();
    wifiConnectionManager.connect();
    mqttClientService.init();

    // Act
    mqttClientService.connect();
    delay(5000); // Warten bis Verbindung aufgebaut ist
    bool mqttConnected = mqttClientService.isConnected();

    // Assert
    TEST_ASSERT_TRUE(mqttConnected);
}