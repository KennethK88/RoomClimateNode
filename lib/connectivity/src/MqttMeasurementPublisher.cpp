#include <MqttMeasurementPublisher.h>
#include <cstddef>
#include <cmath>
#include <cstdio>

namespace
{
    constexpr size_t SIZE_PAYLOAD = 10;
}

void MqttMeasurementPublisher::publish(const Measurements& measurements)
{
    char temperature[SIZE_PAYLOAD];
    char humidity[SIZE_PAYLOAD];
    std::snprintf(temperature, SIZE_PAYLOAD, "%.1f", measurements.temperature);
    std::snprintf(humidity, SIZE_PAYLOAD, "%d", static_cast<int>(std::round(measurements.humidity)));
    mqttClientService.publish("roomclimatenode/livingroom/temperature", temperature);
    mqttClientService.publish("roomclimatenode/livingroom/humidity", humidity);
}