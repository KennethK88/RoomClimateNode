#pragma once
#include <IMeasurementPublisher.h>
#include <MqttClientService.h>

/**
 * @file MqttMeasurementPublisher.h
 * @brief MQTT-basierte Veröffentlichung fachlicher Messwerte.
 */

/**
 * @brief Übersetzt Messwerte des Raumklima-Knotens in MQTT-Nachrichten.
 *
 * Diese Klasse kennt die fachlichen Messwerte und bildet sie auf konkrete
 * MQTT-Topics und Payloads ab. Das eigentliche Senden der Nachrichten wird an
 * den MqttClientService delegiert.
 */
class MqttMeasurementPublisher : public IMeasurementPublisher
{
    private:
        MqttClientService& mqttClientService;

    public:

        /**
         * @brief Erstellt einen MQTT-Messwertpublisher.
         *
         * @param mqttClientService MQTT-Service, der für das Senden der Nachrichten verwendet wird.
         */
        MqttMeasurementPublisher(MqttClientService& mqttClientService) : mqttClientService(mqttClientService) {}

        /**
         * @brief Veröffentlicht die übergebenen Messwerte per MQTT.
         *
         * @param measurements Die zu veröffentlichenden Messwerte.
         */
        void publish(const Measurements& measurements) override;
};