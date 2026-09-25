#pragma once
#include <MqttClientService.h>

class MqttOtaRequestReader
{
    private:
        MqttClientService& mqttClientService;
        bool otaRequested = false;

    public:
        explicit MqttOtaRequestReader(MqttClientService& mqttClientService) : mqttClientService(mqttClientService) {}
        bool subscribe();
        bool update();
        bool isOtaRequested() const;
};