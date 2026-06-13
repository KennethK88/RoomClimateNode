#pragma once
#include <IMeasurementPublisher.h>
#include <MqttClientService.h>

class MqttMeasurementPublisher : public IMeasurementPublisher
{
    private:
        MqttClientService& mqttClientService;

    public:
        MqttMeasurementPublisher(MqttClientService& mqttClientService) : mqttClientService(mqttClientService) {}
        void publish(const Measurements& measurements) override;
};