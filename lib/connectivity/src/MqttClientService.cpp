#include <MqttClientService.h>
#include <cstdint>
#include <Arduino.h>

namespace
{
    const char* mqttClientId = MQTT_CLIENT_ID;
    const char* mqttUser = MQTT_USER;
    const char* mqttPass = MQTT_PASS;
    const char* mqttBroker = MQTT_BROKER;
    const uint16_t mqttPort = MQTT_PORT;
}

void MqttClientService::init() 
{
    mqttClient.setId(mqttClientId);
    mqttClient.setUsernamePassword(mqttUser, mqttPass);
}

void MqttClientService::connect() 
{
    if (isConnected()) return;
    while (!isConnected())
    {
        mqttClient.connect(mqttBroker, mqttPort);
        delay(1000);
    }
}

void MqttClientService::reconnect() 
{
    if (!isConnected()) connect();
}

bool MqttClientService::isConnected()
{
    return mqttClient.connected();
}

bool MqttClientService::publish(const char* topic, const char* payload)
{
    if (!isConnected()) return false;
    mqttClient.beginMessage(topic, true);
    mqttClient.print(payload);
    return mqttClient.endMessage();
}