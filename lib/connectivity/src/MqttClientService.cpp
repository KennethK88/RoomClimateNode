#include <MqttClientService.h>
#include <cstdint>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <Types.h>
#include <cstring>
#include <cstddef>

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

bool MqttClientService::subscribe(const char* topic)
{
    if (topic == nullptr) return false;
    if (!isConnected()) return false;
    return (mqttClient.subscribe(topic) == 1);
}

bool MqttClientService::readMessage(char* topic, std::size_t topicSize, char* payload, std::size_t payloadSize)
{
    if (topic == nullptr) return false;
    if (payload == nullptr) return false;
    if (topicSize == 0) return false;
    if (payloadSize == 0) return false;
    if (!isConnected()) return false;

    int messageSize = mqttClient.parseMessage();
    if (messageSize == 0) return false;
    strncpy(topic, mqttClient.messageTopic().c_str(), topicSize);
    topic[topicSize - 1] = '\0';

    int readPayloadSize = mqttClient.read(reinterpret_cast<uint8_t*>(payload), payloadSize - 1);
    if (readPayloadSize == 0) return false;
    payload[readPayloadSize] = '\0';

    return true;
}

void MqttClientService::disconnect()
{
    mqttClient.stop();
}