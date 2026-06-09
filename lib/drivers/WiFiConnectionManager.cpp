#include <WiFiConnectionManager.h>
#include <WiFiS3.h>

namespace
{
    const char* ssid = SECRET_SSID;
    const char* pass = SECRET_PASS;
}

void WiFiConnectionManager::init() 
{
    if (WiFi.status() == WL_NO_MODULE)
    {
        // ?
    }
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
    connect();
}

bool WiFiConnectionManager::isConnected() const
{
    return (WiFi.status() == WL_CONNECTED);
}
