#pragma once
#include <ISht31SensorDriver.h>
#include <IBatteryDriver.h>
#include <IConnectionManager.h>
#include <IMeasurementPublisher.h>
#include <TemperatureSensor.h>
#include <HumiditySensor.h>
#include <BatterySensor.h>
#include <SensorCoordinator.h>
#include <SensorValidator.h>
#include <StateMachine.h>
#include <PowerManager.h>

/**
 * @file AirMonitorController.h
 * @brief Central orchestration component of the room climate node.
 */

/**
 * @class AirMonitorController
 * @brief Coordinates initialization, measurement acquisition, validation, publishing and power management.
 *
 * The AirMonitorController represents the central control flow of the room
 * climate node. It connects the sensor abstraction, measurement validation,
 * system state evaluation, publishing and power management components.
 *
 * Responsibilities:
 * - Initialize sensor, Wi-Fi and MQTT components
 * - Trigger sensor and battery voltage measurements
 * - Collect temperature, humidity and battery level values
 * - Validate measured values
 * - Calculate the current system state
 * - Publish measurement values using an abstract publisher interface
 * - Trigger deep sleep after one measurement and publishing cycle
 *
 * @note The class does not depend on concrete Wi-Fi, MQTT, SHT31 or battery
 * driver implementations. Concrete implementations are injected through
 * interfaces to keep the application logic testable and largely
 * platform-independent.
 *
 * @note The PowerManager is currently injected as a concrete component and
 * encapsulates the ESP32 deep sleep handling. It may be replaced by an
 * interface in a later refactoring step if controller-level tests require it.
 *
 * @note The class name is historically grown. Functionally, this class
 * represents the main controller of the room climate node.
 */
class AirMonitorController
{
    private:
    
        // Driver interfaces
        ISht31SensorDriver& sht31SensorDriver;
        IBatteryDriver& batteryDriver;

        // Connection interfaces
        IConnectionManager& wifiConnectionManager;
        IConnectionManager& mqttClientService;
        IMeasurementPublisher& measurementPublisher;

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
         * @brief Creates the controller and wires the required components.
         *
         * The constructor receives hardware-related, communication-related and
         * power-management-related dependencies. It uses the sensor driver
         * dependencies to create the application-level sensor objects and the
         * SensorCoordinator.
         *
         * @param sht31SensorDriver Driver interface for the SHT31 temperature and humidity sensor.
         * @param batteryDriver Driver interface for battery voltage measurement.
         * @param wifiConnectionManager Connection manager for the Wi-Fi connection.
         * @param mqttClientService Connection manager for the MQTT connection.
         * @param measurementPublisher Publisher used to publish measurement values.
         * @param powerManager Power manager used to enter deep sleep after a measurement cycle.
         */
        AirMonitorController(ISht31SensorDriver& sht31SensorDriver, IBatteryDriver& batteryDriver, IConnectionManager& wifiConnectionManager, IConnectionManager& mqttClientService, IMeasurementPublisher& measurementPublisher, PowerManager& powerManager) : sht31SensorDriver(sht31SensorDriver), batteryDriver(batteryDriver), wifiConnectionManager(wifiConnectionManager), mqttClientService(mqttClientService), measurementPublisher(measurementPublisher), powerManager(powerManager), temperatureSensor(sht31SensorDriver), humiditySensor(sht31SensorDriver), batterySensor(batteryDriver), sensorCoordinator(temperatureSensor, humiditySensor, batterySensor) {}

        /**
         * @brief Initializes the room climate node.
         *
         * Initializes the connection and sensor-related components and prepares
         * the system for cyclic operation.
         */
        void init();

        /**
         * @brief Executes one measurement, publishing and sleep cycle.
         *
         * Triggers the current sensor and battery measurements, collects the
         * resulting measurement values, validates them, calculates the system
         * state, publishes the measurement data and finally requests deep sleep.
         */
        void update();
};