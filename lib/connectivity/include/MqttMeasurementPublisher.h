#pragma once
#include <IMeasurementPublisher.h>
#include <MqttClientService.h>

/**
 * @file MqttMeasurementPublisher.h
 * @brief MQTT-based publishing of application-level measurement values.
 */

/**
 * @brief Converts room climate measurements into MQTT messages.
 *
 * This class knows the application-level measurement values and maps them to
 * concrete MQTT topics and payloads. The actual message transmission is
 * delegated to the MqttClientService.
 */
class MqttMeasurementPublisher : public IMeasurementPublisher
{
    private:
        MqttClientService& mqttClientService;

    public:

        /**
         * @brief Creates an MQTT measurement publisher.
         *
         * @param mqttClientService MQTT service used to send the messages.
         */
        MqttMeasurementPublisher(MqttClientService& mqttClientService) : mqttClientService(mqttClientService) {}

        /**
         * @brief Publishes the given measurement values via MQTT.
         *
         * The method publishes temperature, humidity and battery level values
         * to their corresponding MQTT topics.
         *
         * @param measurements The measurement values to publish.
         * @return true if all measurement values were published successfully,
         *         false if at least one MQTT publish operation failed.
         */
        bool publish(const Measurements& measurements) override;
};