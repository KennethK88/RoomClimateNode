#include <unity.h>
#include <WiFiConnectionManager.h>
#include <Arduino.h>

void test_wifi_connection_manager_should_establish_wifi_connection()
{
    // NOTE: Dieser Test setzt WiFi Empfang samt korrekter Zugangsdaten voraus.

    // Arrange
    WiFiConnectionManager wifiConnectionManager;
    wifiConnectionManager.init();

    // Act
    wifiConnectionManager.connect();
    delay(5000); // Warten bis Verbindung aufgebaut ist
    bool wifiConnected = wifiConnectionManager.isConnected();

    // Assert
    TEST_ASSERT_TRUE(wifiConnected);
}