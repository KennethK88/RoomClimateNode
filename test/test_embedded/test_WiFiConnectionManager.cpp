#include <WiFiConnectionManager.h>

#include <unity.h>

void test_wifi_connection_manager_should_establish_wifi_connection()
{
    // NOTE: This test requires Wi-Fi coverage and valid credentials.

    // Arrange
    WiFiConnectionManager wifiConnectionManager;
    wifiConnectionManager.init();

    // Act
    wifiConnectionManager.connect();
    const bool wifiConnected = wifiConnectionManager.isConnected();

    // Assert
    TEST_ASSERT_TRUE(wifiConnected);
}