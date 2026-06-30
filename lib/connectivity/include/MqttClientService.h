#pragma once
#include <WiFi.h>
#include <IConnectionManager.h>
#include <ArduinoMqttClient.h>

/**
 * @file MqttClientService.h
 * @brief MQTT connection component for the ESP32-based room climate node.
 *
 * This component uses the ESP32 WiFi stack together with the Arduino MQTT
 * client library to connect to the MQTT broker and publish payloads.
 */

/**
 * @brief Manages the MQTT connection and provides a generic publish function.
 *
 * This class encapsulates the Arduino MQTT client and handles initialization,
 * connection setup, reconnection and publishing payloads to arbitrary MQTT
 * topics.
 *
 * The class does not know any domain-specific measurement values. Translating
 * measurement data into concrete MQTT topics and payloads is handled outside
 * this class.
 *
 * The underlying network connection is provided by the ESP32 WiFi client.
 */
class MqttClientService : public IConnectionManager
{
    private:
        WiFiClient wifiClient;
        MqttClient mqttClient{wifiClient};

    public:

        /**
         * @brief Erzeugt einen MQTT-Client-Service.
         */
        MqttClientService() = default;

        /**
         * @brief Initialisiert den MQTT-Client.
         *
         * Setzt MQTT-Client-ID und Zugangsdaten.
         */
        void init() override;

        /**
         * @brief Baut die Verbindung zum MQTT-Broker auf.
         */
        void connect() override;

        /**
         * @brief Stellt die MQTT-Verbindung bei Bedarf erneut her.
         */
        void reconnect() override;

        /**
         * @brief Prüft, ob die MQTT-Verbindung aktuell besteht.
         *
         * @return true, wenn der MQTT-Client mit dem Broker verbunden ist, sonst false.
         */
        bool isConnected() override;

        /**
         * @brief Veröffentlicht eine Payload auf einem MQTT-Topic.
         *
         * @param topic MQTT-Topic, auf dem veröffentlicht werden soll.
         * @param payload Zu veröffentlichende Nutzdaten.
         * @return true, wenn die Nachricht erfolgreich veröffentlicht wurde, sonst false.
         */
        bool publish(const char* topic, const char* payload);
};