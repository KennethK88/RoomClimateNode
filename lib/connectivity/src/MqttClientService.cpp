#include <MqttClientService.h>
#include <cstdint>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <Types.h>

namespace
{
    const char* mqttClientId = MQTT_CLIENT_ID;
    const char* mqttUser = MQTT_USER;
    const char* mqttPass = MQTT_PASS;
    const char* mqttBroker = MQTT_BROKER;
    const uint16_t mqttPort = MQTT_PORT;
    constexpr Milliseconds MQTT_CONNECT_TIMEOUT_MS = 10000;
    constexpr Milliseconds MQTT_CONNECT_RETRY_INTERVAL_MS = 1000;
}

void MqttClientService::init() 
{
    mqttClient.setId(mqttClientId);
    mqttClient.setUsernamePassword(mqttUser, mqttPass);
}

void MqttClientService::connect() 
{
    if (isConnected()) return;
    Milliseconds startTime = millis();
    while (((millis() - startTime) < MQTT_CONNECT_TIMEOUT_MS) && !isConnected())
    {
        if (mqttClient.connect(mqttBroker, mqttPort) != 0) return;
        vTaskDelay(pdMS_TO_TICKS(MQTT_CONNECT_RETRY_INTERVAL_MS));
    }
}

bool MqttClientService::isConnected()
{
    return mqttClient.connected();
}

bool MqttClientService::publish(const char* topic, const char* payload)
{
    if (!isConnected()) return false;
    mqttClient.beginMessage(topic, true, 1);
    mqttClient.print(payload);
    return (mqttClient.endMessage() != 0);
}