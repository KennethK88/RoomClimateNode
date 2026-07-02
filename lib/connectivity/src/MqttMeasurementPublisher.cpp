#include <MqttMeasurementPublisher.h>
#include <cstddef>
#include <cmath>
#include <cstdio>

namespace
{
    constexpr size_t SIZE_PAYLOAD = 10;
}

bool MqttMeasurementPublisher::publish(const Measurements& measurements)
{
    char temperature[SIZE_PAYLOAD];
    char humidity[SIZE_PAYLOAD];
    char batteryLevel[SIZE_PAYLOAD];

    std::snprintf(temperature, SIZE_PAYLOAD, "%.1f", measurements.temperature);
    std::snprintf(humidity, SIZE_PAYLOAD, "%d", static_cast<int>(std::round(measurements.humidity)));
    std::snprintf(batteryLevel, SIZE_PAYLOAD, "%d", static_cast<int>(measurements.batteryLevel));

    bool temperaturePublished = mqttClientService.publish("roomclimatenode/livingroom/temperature", temperature);
    bool humidityPublished = mqttClientService.publish("roomclimatenode/livingroom/humidity", humidity);
    bool batteryLevelPublished = mqttClientService.publish("roomclimatenode/livingroom/battery_level", batteryLevel);

    return (temperaturePublished && humidityPublished && batteryLevelPublished);
}