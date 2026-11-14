#pragma once

#include "Measurements.h"

#include <MqttClientService.h>

/**
 * @file MqttMeasurementPublisher.h
 * @brief Defines the MQTT publisher for RoomClimateNode measurements.
 */

/**
 * @brief Publishes room climate measurements via MQTT.
 *
 * Maps application-specific temperature, humidity, and battery level
 * measurements to their corresponding MQTT topics and payloads.
 *
 * The actual MQTT communication is delegated to MqttClientService.
 */
class MqttMeasurementPublisher
{
    private:
        MqttClientService& mqttClientService;

    public:

        /**
         * @brief Constructs an MQTT measurement publisher.
         *
         * @param mqttClientService MQTT service responsible for message transmission.
         */
        MqttMeasurementPublisher(MqttClientService& mqttClientService) : mqttClientService(mqttClientService) {}

        /**
         * @brief Publishes temperature, humidity, and battery level measurements.
         *
         * Each measurement is published to its corresponding MQTT topic.
         *
         * @param measurements Measurement values to publish.
         * @return true if all MQTT publish operations succeed,
         *         false if at least one operation fails.
         */
        bool publish(const Measurements& measurements);
};