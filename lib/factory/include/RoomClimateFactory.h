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
 * @brief Defines the factory responsible for constructing the RoomClimateNode components.
 */

/**
 * @brief Creates and connects the components required by the RoomClimateNode.
 *
 * The RoomClimateFactory acts as the central composition point of the application.
 * It owns the concrete hardware drivers, communication services, MQTT publishers,
 * firmware update components, and power management components.
 *
 * These dependencies are constructed and injected into the RoomClimateController,
 * keeping component creation separate from the application's control logic.
 *
 * The factory manages the lifetime of all components, ensuring that their
 * dependencies remain valid throughout the controller's lifetime.
 *
 * Responsibilities:
 * - Construct the SHT31 and battery drivers
 * - Construct Wi-Fi and MQTT communication services
 * - Construct measurement and firmware information publishers
 * - Construct OTA update and request handling components
 * - Construct the power management component
 * - Assemble and provide the RoomClimateController
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
         * @brief Returns the fully constructed RoomClimateController instance.
         *
         * @return Reference to the controller owned by this factory.
         *
         * @note The returned reference remains valid only while the
         *       RoomClimateFactory instance exists.
         */
        RoomClimateController& getRoomClimateController();
};