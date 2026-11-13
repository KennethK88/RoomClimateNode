#include "MqttMeasurementPublisher.h"

#include <cstddef>
#include <cmath>
#include <cstdio>

namespace
{
    constexpr size_t SIZE_PAYLOAD = 10;
    const char* temperatureTopic = MQTT_BASE_TOPIC "/temperature";
    const char* humidityTopic = MQTT_BASE_TOPIC "/humidity";
    const char* batteryLevelTopic = MQTT_BASE_TOPIC "/battery_level";
}

bool MqttMeasurementPublisher::publish(const Measurements& measurements)
{
    char temperature[SIZE_PAYLOAD];
    char humidity[SIZE_PAYLOAD];
    char batteryLevel[SIZE_PAYLOAD];

    std::snprintf(temperature, SIZE_PAYLOAD, "%.1f", measurements.temperature);
    std::snprintf(humidity, SIZE_PAYLOAD, "%d", static_cast<int>(std::round(measurements.humidity)));
    std::snprintf(batteryLevel, SIZE_PAYLOAD, "%d", static_cast<int>(measurements.batteryLevel));

    bool temperaturePublished = mqttClientService.publish(temperatureTopic, temperature, true);
    bool humidityPublished = mqttClientService.publish(humidityTopic, humidity, true);
    bool batteryLevelPublished = mqttClientService.publish(batteryLevelTopic, batteryLevel, true);

    return (temperaturePublished && humidityPublished && batteryLevelPublished);
}