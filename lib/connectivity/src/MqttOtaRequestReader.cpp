#include "MqttOtaRequestReader.h"
#include <cstddef>
#include <cstring>

namespace
{
    constexpr std::size_t SIZE_PAYLOAD = 10;
    constexpr std::size_t SIZE_TOPIC = 64;
    const char* otaRequestTopicTarget = MQTT_BASE_TOPIC "/ota/request";
}

bool MqttOtaRequestReader::subscribe()
{
    return mqttClientService.subscribe(otaRequestTopicTarget);
}

bool MqttOtaRequestReader::update()
{
    char otaRequestPayload[SIZE_PAYLOAD];
    char otaRequestTopic[SIZE_TOPIC];

    const bool readMessageSuccess = mqttClientService.readMessage(otaRequestTopic, SIZE_TOPIC, otaRequestPayload, SIZE_PAYLOAD);

    if (!readMessageSuccess) return false;
    if (strcmp(otaRequestTopic, otaRequestTopicTarget) != 0) return false;
    if (strcmp(otaRequestPayload, "true") == 0) otaRequested = true;
    else if (strcmp(otaRequestPayload, "false") == 0) otaRequested = false;
    else return false;

    return true;
}

bool MqttOtaRequestReader::isOtaRequested() const
{
    return otaRequested;
}