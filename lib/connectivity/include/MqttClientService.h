#pragma once
#include <WiFi.h>
#include <IConnectionManager.h>
#include <ArduinoMqttClient.h>

/**
 * @file MqttClientService.h
 * @brief MQTT connection component for the ESP32-based room climate node.
 *
 * This component uses the ESP32 Wi-Fi stack together with the Arduino MQTT
 * client library to connect to the MQTT broker and publish payloads.
 */

/**
 * @brief Manages the MQTT connection and provides a generic publish function.
 *
 * This class encapsulates the Arduino MQTT client and handles initialization,
 * connection setup and publishing payloads to arbitrary MQTT topics.
 *
 * The class does not know any domain-specific measurement values. Translating
 * measurement data into concrete MQTT topics and payloads is handled outside
 * this class.
 *
 * Published messages are sent as retained MQTT messages with QoS 1. This allows
 * the broker to keep the latest value per topic and provides broker-side
 * acknowledgement before the node enters deep sleep.
 *
 * The underlying network connection is provided by the ESP32 Wi-Fi client.
 */
class MqttClientService : public IConnectionManager
{
    private:
        WiFiClient wifiClient;
        MqttClient mqttClient{wifiClient};

    public:

        /**
         * @brief Creates an MQTT client service.
         */
        MqttClientService() = default;

        /**
         * @brief Initializes the MQTT client.
         *
         * Sets the MQTT client ID and authentication credentials.
         */
        void init() override;

        /**
         * @brief Attempts to connect to the MQTT broker.
         *
         * The method retries the MQTT connection setup until the connection is
         * established or the internal connection timeout is reached. The result
         * can be checked using isConnected().
         */
        void connect() override;

        /**
         * @brief Checks whether the MQTT client is currently connected.
         *
         * @return true if the MQTT client is connected to the broker,
         *         false otherwise.
         */
        bool isConnected() override;

        /**
         * @brief Publishes a payload to an MQTT topic.
         *
         * The message is published as a retained MQTT message with QoS 1.
         *
         * @param topic MQTT topic to publish to.
         * @param payload Payload to publish.
         * @return true if the message was published successfully,
         *         false otherwise.
         */
        bool publish(const char* topic, const char* payload);
        bool subscribe(const char* topic);
        bool readMessage(char* topic, std::size_t topicSize, char* payload, std::size_t payloadSize);
        void disconnect() override;
};