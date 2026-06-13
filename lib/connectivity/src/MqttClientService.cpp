#include <MqttClientService.h>
#include <Arduino.h>
#include <cstdint>

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
    mqttClient.connect(mqttBroker, mqttPort);
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
    mqttClient.beginMessage(topic);
    mqttClient.print(payload);
    return mqttClient.endMessage();
}