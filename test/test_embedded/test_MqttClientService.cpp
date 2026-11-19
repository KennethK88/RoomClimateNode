#include <MqttClientService.h>
#include <WiFiConnectionManager.h>

#include <unity.h>

void test_mqtt_client_service_should_establish_connection_to_broker()
{
    // NOTE: This test requires Wi-Fi coverage, valid credentials, and a reachable MQTT broker.

    // Arrange
    WiFiConnectionManager wifiConnectionManager;
    MqttClientService mqttClientService;
    wifiConnectionManager.init();
    wifiConnectionManager.connect();
    const bool wifiConnected = wifiConnectionManager.isConnected();
    TEST_ASSERT_TRUE_MESSAGE(wifiConnected, "Wi-Fi connection failed");
    mqttClientService.init();

    // Act
    mqttClientService.connect();
    const bool mqttConnected = mqttClientService.isConnected();

    // Assert
    TEST_ASSERT_TRUE(mqttConnected);
}