#pragma once
#ifdef ARDUINO_ARCH_ESP32
    #include <WiFi.h>
#else
    #include <WiFiS3.h>
#endif
#include <IConnectionManager.h>
#include <ArduinoMqttClient.h>

/**
 * @file MqttClientService.h
 * @brief Konkrete MQTT-Verbindungskomponente für den Raumklima-Knoten.
 *
 * Der MQTT-Service nutzt abhängig vom Build-Target die passende Arduino-WiFi-
 * Bibliothek. Auf dem Arduino Uno R4 WiFi / RA4M1 wird WiFiS3 verwendet, auf
 * ESP32-Zielplattformen die ESP32-WiFi-Bibliothek.
 */

/**
 * @brief Verwaltet die MQTT-Verbindung und stellt eine generische Publish-Funktion bereit.
 *
 * Diese Klasse kapselt den Arduino MQTT-Client und übernimmt Initialisierung,
 * Verbindungsaufbau, Wiederverbindung und das Veröffentlichen von Payloads auf
 * beliebigen MQTT-Topics.
 *
 * Die Klasse kennt keine fachlichen Messwerte. Die Übersetzung von Messwerten
 * in konkrete MQTT-Topics und Payloads erfolgt außerhalb dieser Klasse.
 *
 * Die darunterliegende WiFi-Client-Implementierung wird abhängig von der
 * Zielplattform ausgewählt. Dadurch bleibt die MQTT-Schnittstelle für die
 * Anwendung identisch, während RA4M1- und ESP32-basierte Builds unterschiedliche
 * WiFi-Stacks verwenden können.
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