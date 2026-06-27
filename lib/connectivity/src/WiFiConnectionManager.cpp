#include <WiFiConnectionManager.h>
#ifdef ARDUINO_ARCH_ESP32
    #include <WiFi.h>
#else
    #include <WiFiS3.h>
#endif

namespace
{
    const char* ssid = SECRET_SSID;
    const char* pass = SECRET_PASS;
}

void WiFiConnectionManager::init()
{
    #ifdef ARDUINO_ARCH_ESP32
        WiFi.mode(WIFI_STA);
    #else
        if (WiFi.status() == WL_NO_MODULE)
        {
            // ?
        }
    #endif
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
