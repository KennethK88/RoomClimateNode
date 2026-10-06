#include <WiFiConnectionManager.h>
#include <WiFi.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <Types.h>

namespace
{
    const char* ssid = SECRET_SSID;
    const char* pass = SECRET_PASS;
    constexpr Milliseconds WIFI_CONNECT_TIMEOUT_MS = 10000;
    constexpr Milliseconds WIFI_CONNECT_POLL_INTERVAL_MS = 500;
}

void WiFiConnectionManager::init()
{
    WiFi.mode(WIFI_STA);
}

void WiFiConnectionManager::connect() 
{
    if (isConnected()) return;
    Milliseconds startTime = millis();
    WiFi.begin(ssid, pass);
    while (((millis() - startTime) < WIFI_CONNECT_TIMEOUT_MS) && !isConnected())
    {
        vTaskDelay(pdMS_TO_TICKS(WIFI_CONNECT_POLL_INTERVAL_MS));
    }
}

bool WiFiConnectionManager::isConnected()
{
    return (WiFi.status() == WL_CONNECTED);
}

void WiFiConnectionManager::disconnect()
{
    
}
