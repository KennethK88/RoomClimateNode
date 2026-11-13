#pragma once

#include "ISht31SensorDriver.h"
#include "MqttMeasurementPublisher.h"
#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include "SensorCoordinator.h"
#include "SensorValidator.h"
#include "StateMachine.h"
#include "PowerManager.h"

#include <IBatteryDriver.h>
#include <WiFiConnectionManager.h>
#include <MqttClientService.h>
#include <BatterySensor.h>
#include <FirmwareUpdateService.h>
#include <MqttOtaRequestReader.h>
#include <MqttOtaStatusPublisher.h>
#include <MqttFirmwareVersionPublisher.h>

/**
 * @file RoomClimateController.h
 * @brief Defines the central application controller of the RoomClimateNode.
 */

/**
 * @brief Orchestrates the measurement, communication, OTA, and power management workflow.
 *
 * The RoomClimateController coordinates the main application lifecycle
 * of the RoomClimateNode.
 *
 * It manages network connectivity, sensor measurements, MQTT publishing,
 * firmware information reporting, OTA update requests, and deep sleep.
 *
 * Hardware-specific sensor operations are accessed through driver interfaces.
 * Communication services and power management components are provided
 * through constructor-based dependency injection.
 *
 * Responsibilities:
 * - Initialize sensor drivers and communication components
 * - Establish Wi-Fi and MQTT connections
 * - Publish firmware version and OTA window status information
 * - Process OTA update requests and execute maintenance windows
 * - Trigger temperature, humidity, and battery voltage measurements
 * - Collect measurement values through the SensorCoordinator
 * - Publish measurement values via MQTT
 * - Request deep sleep after completing the application cycle
 *
 * @note The controller depends on abstract sensor driver interfaces,
 * but currently uses concrete communication and power management components.
 */
class RoomClimateController
{
    private:
    
        // Driver interfaces
        ISht31SensorDriver& sht31SensorDriver;
        IBatteryDriver& batteryDriver;

        // Communication and OTA components
        WiFiConnectionManager& wifiConnectionManager;
        MqttClientService& mqttClientService;
        MqttMeasurementPublisher& mqttMeasurementPublisher;
        FirmwareUpdateService& firmwareUpdateService;
        MqttOtaRequestReader& mqttOtaRequestReader;
        MqttOtaStatusPublisher& mqttOtaStatusPublisher;
        MqttFirmwareVersionPublisher& mqttFirmwareVersionPublisher;

        // Power
        PowerManager& powerManager;

        // Sensors
        TemperatureSensor temperatureSensor;
        HumiditySensor humiditySensor;
        BatterySensor batterySensor;
        SensorCoordinator sensorCoordinator;

        // Evaluation
        SensorValidator sensorValidator;
        StateMachine stateMachine;

 
    public:

        /**
         * @brief Constructs the central RoomClimateNode controller.
         *
         * Receives the hardware drivers, communication services, OTA components,
         * and power manager required for application operation.
         *
         * Initializes the application-level sensor components and connects
         * them through the SensorCoordinator.
         *
         * Dependencies are provided by reference and must remain valid
         * throughout the controller's lifetime.
         *
         * @param sht31SensorDriver Driver interface for temperature and humidity measurements.
         * @param batteryDriver Driver interface for battery voltage measurements.
         * @param wifiConnectionManager Service responsible for Wi-Fi connectivity.
         * @param mqttClientService Service responsible for MQTT communication.
         * @param mqttMeasurementPublisher Publisher for application measurement values.
         * @param firmwareUpdateService Service responsible for OTA firmware updates.
         * @param mqttOtaRequestReader Component for receiving OTA update requests.
         * @param mqttOtaStatusPublisher Publisher for OTA maintenance window status.
         * @param mqttFirmwareVersionPublisher Publisher for firmware version information.
         * @param powerManager Component responsible for deep sleep handling.
         */
        RoomClimateController(ISht31SensorDriver& sht31SensorDriver, IBatteryDriver& batteryDriver, WiFiConnectionManager& wifiConnectionManager, MqttClientService& mqttClientService, MqttMeasurementPublisher& mqttMeasurementPublisher, FirmwareUpdateService& firmwareUpdateService, MqttOtaRequestReader& mqttOtaRequestReader, MqttOtaStatusPublisher& mqttOtaStatusPublisher, MqttFirmwareVersionPublisher& mqttFirmwareVersionPublisher, PowerManager& powerManager) : sht31SensorDriver(sht31SensorDriver), batteryDriver(batteryDriver), wifiConnectionManager(wifiConnectionManager), mqttClientService(mqttClientService), mqttMeasurementPublisher(mqttMeasurementPublisher), firmwareUpdateService(firmwareUpdateService), mqttOtaRequestReader(mqttOtaRequestReader), mqttOtaStatusPublisher(mqttOtaStatusPublisher), mqttFirmwareVersionPublisher(mqttFirmwareVersionPublisher), powerManager(powerManager), temperatureSensor(sht31SensorDriver), humiditySensor(sht31SensorDriver), batterySensor(batteryDriver), sensorCoordinator(temperatureSensor, humiditySensor, batterySensor) {}

        /**
         * @brief Initializes the components required for application operation.
         *
         * Initializes the Wi-Fi and MQTT services, followed by the SHT31
         * sensor driver and battery driver.
         *
         * @note Wi-Fi initialization currently needs to precede I2C
         * initialization due to an unresolved hardware or software interaction.
         */
        void init();

        /**
         * @brief Executes the main RoomClimateNode application cycle.
         *
         * Establishes Wi-Fi and MQTT connectivity and publishes the current
         * OTA window status and firmware version.
         *
         * Checks for OTA update requests during a short polling window.
         * If an update is requested and the firmware update service initializes
         * successfully, an OTA maintenance window is opened.
         *
         * After OTA processing, the method acquires temperature, humidity,
         * and battery measurements, collects the results through the
         * SensorCoordinator, and publishes them via MQTT.
         *
         * @note Measurement validation and system state evaluation are currently
         * performed, but their results do not affect MQTT publishing.
         *
         * @note If Wi-Fi or MQTT connectivity cannot be established, the
         * measurement cycle is aborted and deep sleep is requested.
         *
         * @note After publishing, the MQTT connection is disconnected
         * and deep sleep is requested.
         */
        void update();
};