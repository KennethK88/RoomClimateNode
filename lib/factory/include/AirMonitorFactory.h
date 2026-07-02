#pragma once
#include <Sht31Driver.h>
#include <ESP32BatteryDriver.h>
#include <WiFiConnectionManager.h>
#include <MqttClientService.h>
#include <MqttMeasurementPublisher.h>
#include <PowerManager.h>
#include <AirMonitorController.h>

/**
 * @file AirMonitorFactory.h
 * @brief Factory for creating and wiring the room climate node.
 */

/**
 * @class AirMonitorFactory
 * @brief Creates the concrete components and wires the central controller.
 *
 * The AirMonitorFactory encapsulates the system setup. It creates the concrete
 * sensor, battery, Wi-Fi, MQTT and power management components and wires them
 * with the AirMonitorController.
 *
 * This keeps the AirMonitorController decoupled from concrete hardware and
 * communication implementations. In tests, the controller can therefore be
 * used with fake components for most dependencies.
 *
 * Responsibilities:
 * - Create concrete sensor, battery and connection components
 * - Create the MQTT-based measurement publisher
 * - Create the power manager used for ESP32 deep sleep handling
 * - Wire the components with the AirMonitorController
 * - Provide a fully constructed controller instance
 *
 * @note The class name AirMonitorController is historically grown. Functionally,
 * this factory currently builds the main controller of a room climate node.
 */
class AirMonitorFactory
{
    private:
        Sht31Driver sht31Driver;
        ESP32BatteryDriver esp32BatteryDriver;
        WiFiConnectionManager wifiConnectionManager;
        MqttClientService mqttClientService;
        MqttMeasurementPublisher mqttMeasurementPublisher{mqttClientService};
        PowerManager powerManager;
        AirMonitorController airMonitorController{sht31Driver, esp32BatteryDriver, wifiConnectionManager, mqttClientService, mqttMeasurementPublisher, powerManager};

    public:
    
        /**
         * @brief Returns the fully wired AirMonitorController instance.
         *
         * @return Reference to the constructed AirMonitorController.
         */
        AirMonitorController& getAirMonitorController();
};