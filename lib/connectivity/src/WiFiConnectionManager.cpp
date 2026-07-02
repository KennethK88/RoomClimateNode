#include <WiFiConnectionManager.h>
#include <WiFi.h>
#include <Arduino.h>

namespace
{
    const char* ssid = SECRET_SSID;
    const char* pass = SECRET_PASS;
}

void WiFiConnectionManager::init()
{
    WiFi.mode(WIFI_STA);
}

void WiFiConnectionManager::connect() 
{
    if (isConnected()) return;
    WiFi.begin(ssid, pass);
    while (!isConnected()) delay(1000);
}

void WiFiConnectionManager::reconnect() 
{
    if (!isConnected()) connect();
}

bool WiFiConnectionManager::isConnected()
{
    return (WiFi.status() == WL_CONNECTED);
}
