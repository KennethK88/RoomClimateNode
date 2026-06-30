#include <WiFiConnectionManager.h>
#include <WiFi.h>

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
    if (WiFi.status() != WL_CONNECTED)
    {
        WiFi.begin(ssid, pass);
    }
}

void WiFiConnectionManager::reconnect() 
{
    if (!isConnected()) connect();
}

bool WiFiConnectionManager::isConnected()
{
    return (WiFi.status() == WL_CONNECTED);
}
