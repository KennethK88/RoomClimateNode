# Project Overview: RoomClimateNode

## Project Goal

The goal of this project is to develop a compact, battery-powered
ESP32-based room climate monitoring node.

The node measures ambient temperature, relative humidity, and battery
level and transmits the collected data via Wi-Fi and MQTT to a
Home Assistant environment.

The system is designed for low-power operation using ESP32 deep sleep,
allowing autonomous operation over extended periods.

The project emphasizes modular software architecture, reusable
components, hardware abstraction, and maintainability.


## Current Status

The RoomClimateNode is operational and deployed in a Home Assistant
environment.

### Sensor Measurements

Temperature and relative humidity are measured using an SHT31 sensor.

Battery voltage is measured through the board-specific ADC circuitry
and converted into a battery level percentage.

The current battery level calculation uses a linear voltage-to-percentage
mapping. A more accurate discharge curve is planned.

Measurement values are collected by the SensorCoordinator and
published via MQTT.

A SensorValidator is implemented, but its validation results do not
currently prevent invalid measurements from being published.

### Communication

The node communicates through Wi-Fi and MQTT with a Mosquitto broker
running in the Home Assistant environment.

The following information is published:

- Temperature
- Relative humidity
- Battery level
- Firmware version
- OTA maintenance window status

Home Assistant uses these values for monitoring and visualization.

### Power Management

The node uses ESP32 deep sleep to reduce power consumption.

The current operating cycle is:

1. Wake up from deep sleep.
2. Initialize hardware and communication components.
3. Establish Wi-Fi and MQTT connections.
4. Process potential OTA update requests.
5. Acquire sensor and battery measurements.
6. Publish measurement values via MQTT.
7. Disconnect and return to deep sleep.

The deep sleep interval is currently configured to 15 minutes.

Battery-powered operation has been tested during extended runtime.

### Firmware Updates

Over-the-air firmware updates are supported through an MQTT-controlled
maintenance window.

An OTA request can be issued through Home Assistant.

During the next regular wake-up cycle, the node processes the request
and opens a temporary maintenance window.

Within this window, new firmware can be uploaded wirelessly.

The node publishes the maintenance window status via MQTT.

Fully automated OTA deployment is not yet implemented.

### Supported Hardware

The firmware currently supports:

- LOLIN D32 (ESP32)
- LOLIN C3 Pico (ESP32-C3)

Board-specific configurations are selected at compile time.

The LOLIN D32 is used for the established room climate nodes.
The LOLIN C3 Pico has been evaluated as an alternative platform.

A dedicated enclosure has been developed for the LOLIN D32 version.
Further hardware miniaturization may be considered in future revisions.


## Software Architecture

The application follows a modular, component-oriented architecture.

The RoomClimateController coordinates communication, measurement
acquisition, OTA processing, and power management.

The RoomClimateFactory constructs the required components and
connects their dependencies.

Hardware-specific functionality is separated from application-level
sensor components through driver interfaces.

Common functionality is provided by the separate EmbeddedNodeLibs
library collection.

Reusable components include:

- Battery measurement and battery level calculation
- Wi-Fi connection management
- MQTT communication
- OTA request handling
- Firmware update services
- OTA status publishing
- Firmware version publishing

Additional architecture details are documented using UML class
and sequence diagrams.


## Functional Scope

### Measurement and Communication

- [x] Measure room temperature
- [x] Measure relative humidity
- [x] Measure battery voltage
- [x] Calculate battery level
- [x] Publish measurements via Wi-Fi/MQTT
- [x] Integrate measurements into Home Assistant
- [x] Publish firmware version information
- [ ] Prevent invalid measurements from being published

### Power Management

- [x] Support battery-powered operation
- [x] Implement timer-based deep sleep
- [x] Support periodic measurement and publishing cycles
- [ ] Implement a non-linear battery discharge curve

### Firmware Updates

- [x] Implement OTA firmware updates
- [x] Implement MQTT-controlled OTA maintenance windows
- [x] Publish OTA maintenance window status
- [ ] Implement fully automated OTA deployment


## Required Hardware

- [x] ESP32-based microcontroller
- [x] Rechargeable LiPo battery
- [x] Battery charging circuitry integrated into the development board
- [x] SHT31 temperature and humidity sensor
- [x] Enclosure for the LOLIN D32


## Test Strategy

### Native Tests

- Test application logic independently of target hardware
- Test sensor measurement validation
- Test measurement processing using fake components
- Test applicable error conditions and boundary values

### Embedded Tests

- Verify sensor communication on target hardware
- Verify battery voltage measurement
- Verify Wi-Fi and MQTT communication
- Verify OTA firmware updates
- Verify deep sleep and timer-based wake-up

### Manual System Tests

- Verify the complete wake-connect-measure-publish-sleep cycle
- Verify integration with Mosquitto and Home Assistant
- Monitor battery-powered operation over extended periods
- Verify firmware version and OTA status reporting