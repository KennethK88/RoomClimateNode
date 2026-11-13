#pragma once
#include "Sht31Driver.h"
#include <ESP32BatteryDriver.h>
#include <WiFiConnectionManager.h>
#include <MqttClientService.h>
#include "MqttMeasurementPublisher.h"
#include "PowerManager.h"
#include "RoomClimateController.h"
#include <FirmwareUpdateService.h>
#include <MqttOtaRequestReader.h>
#include <MqttOtaStatusPublisher.h>
#include <MqttFirmwareVersionPublisher.h>
#include "HardwareConfig.h"

/**
 * @file RoomClimateFactory.h
 * @brief Factory for creating and wiring the room climate node.
 */

/**
 * @class RoomClimateFactory
 * @brief Creates the concrete components and wires the central controller.
 *
 * The RoomClimateFactory encapsulates the system setup. It creates the concrete
 * sensor, battery, Wi-Fi, MQTT and power management components and wires them
 * with the RoomClimateController.
 *
 * This keeps the RoomClimateController decoupled from concrete hardware and
 * communication implementations. In tests, the controller can therefore be
 * used with fake components for most dependencies.
 *
 * Responsibilities:
 * - Create concrete sensor, battery and connection components
 * - Create the MQTT-based measurement publisher
 * - Create the power manager used for ESP32 deep sleep handling
 * - Wire the components with the RoomClimateController
 * - Provide a fully constructed controller instance
 *
 * @note The class name RoomClimateController is historically grown. Functionally,
 * this factory currently builds the main controller of a room climate node.
 */
class RoomClimateFactory
{
    private:
        Sht31Driver sht31Driver;
        ESP32BatteryDriver esp32BatteryDriver{HardwareConfig::BATTERY_ADC_PIN, HardwareConfig::BATTERY_VOLTAGE_DIVIDER_FACTOR};
        WiFiConnectionManager wifiConnectionManager;
        MqttClientService mqttClientService;
        MqttMeasurementPublisher mqttMeasurementPublisher{mqttClientService};
        PowerManager powerManager;
        FirmwareUpdateService firmwareUpdateService;
        MqttOtaRequestReader mqttOtaRequestReader{mqttClientService};
        MqttOtaStatusPublisher mqttOtaStatusPublisher{mqttClientService};
        MqttFirmwareVersionPublisher mqttFirmwareVersionPublisher{mqttClientService};
        RoomClimateController roomClimateController{sht31Driver, esp32BatteryDriver, wifiConnectionManager, mqttClientService, mqttMeasurementPublisher, firmwareUpdateService, mqttOtaRequestReader, mqttOtaStatusPublisher, mqttFirmwareVersionPublisher, powerManager};

    public:
    
        /**
         * @brief Returns the fully wired RoomClimateController instance.
         *
         * @return Reference to the constructed RoomClimateController.
         */
        RoomClimateController& getRoomClimateController();
};