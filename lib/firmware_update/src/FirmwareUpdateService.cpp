#include "FirmwareUpdateService.h"
#include "Types.h"
#include <ArduinoOTA.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <WiFi.h>

namespace
{
    constexpr Milliseconds OTA_MAINTENANCE_WINDOW_MS = 300000; // 5 min
    constexpr Milliseconds OTA_HANDLE_INTERVAL_MS = 20;
}

bool FirmwareUpdateService::init()
{
    if (!WiFi.setTxPower(WIFI_POWER_8_5dBm)) return false;
    ArduinoOTA.setHostname(MQTT_CLIENT_ID);
    ArduinoOTA.setPassword(OTA_PASS);
    ArduinoOTA.begin();
    return true;
}

void FirmwareUpdateService::handle()
{
    ArduinoOTA.handle();
}

bool FirmwareUpdateService::runMaintenanceWindow()
{
    const Milliseconds startTime = millis();
    while ((millis() - startTime) < OTA_MAINTENANCE_WINDOW_MS)
    {
        handle();
        vTaskDelay(pdMS_TO_TICKS(OTA_HANDLE_INTERVAL_MS));
    }
    return true;
}