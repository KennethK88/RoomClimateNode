#pragma once
#include <IConnectionManager.h>
#include <WiFiS3.h>
#include <ArduinoMqttClient.h>

class MqttClientService : public IConnectionManager
{
    private:
        WiFiClient wifiClient;
        MqttClient mqttClient{wifiClient};

    public:
        MqttClientService() = default;
        void init() override;
        void connect() override;
        void reconnect() override;
        bool isConnected() override;
        bool publish(const char* topic, const char* payload);
};