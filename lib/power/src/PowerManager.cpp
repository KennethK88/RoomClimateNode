#include "PowerManager.h"
#include "PowerConfig.h"
#include <esp_sleep.h>

bool PowerManager::configureWakeUp()
{
    esp_err_t result = esp_sleep_enable_timer_wakeup(PowerConfig::DEEP_SLEEP_DURATION_SECONDS * PowerConfig::MICROSECONDS_PER_SECOND);
    return result == ESP_OK;
}

void PowerManager::enterDeepSleep()
{
    if (!configureWakeUp()) return;
    esp_deep_sleep_start();
}