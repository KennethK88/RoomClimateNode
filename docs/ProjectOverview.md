# Project Overview: AirMonitorController

## Project Goal

The goal of this project is to develop a compact, battery-powered microcontroller-based room climate node. The node measures temperature and humidity values, processes and validates the measurement data locally, and transmits it wirelessly to a smart home system. The system is intended to operate as a low-power sensor node and provide its measurement values for visualization, monitoring and automation in a Home Assistant environment. Due to the fireplace in the living room, an optional separate CO sensor node is planned for this room.


## Current Status

The room climate node currently measures temperature and humidity using an SHT31 sensor. The measured values are processed locally, validated and published via Wi-Fi/MQTT to a Mosquitto broker. The broker runs as part of the Home Assistant environment on a Raspberry Pi.

The project is running successfully on the ESP32 target hardware. Temperature, humidity and battery level values are received by Home Assistant and are assigned to the corresponding room climate node device.

Battery-powered operation has been validated. The battery voltage is measured through the board-specific voltage measurement circuit, converted into a battery level percentage and included in the normal measurement publishing flow.

Low-power operation using ESP32 deep sleep has been implemented. The node wakes up periodically, connects to Wi-Fi and MQTT, reads the sensor and battery values, publishes the measurements and returns to deep sleep after the measurement cycle. The current deep sleep interval is configured to 15 minutes.


## Planned Functional Scope

- [x] Measure values
    - [x] Room temperature in °C
    - [x] Relative humidity in %
    - [x] Battery level in %
- [x] Validate measured values
    - [x] Room temperature in °C
    - [x] Relative humidity in %
    - [x] Battery level in %
- [x] Provide measured values via Wi-Fi/MQTT
    - [x] Room temperature in °C
    - [x] Relative humidity in %
    - [x] Battery level in % 
- [x] Enable battery-powered operation
- [x] Put the microcontroller into deep sleep between measurement cycles
- [ ] Enable firmware updates via over-the-air update (OTA)
- [ ] Optional: Display system states using an RGB status LED
    - [ ] Indicate low battery level
    - [ ] Indicate implausible measured values
    - [ ] Indicate failed Wi-Fi/MQTT connection
    - [ ] Indicate fully charged battery while connected to the charger
- [ ] Optional: Measure CO values using a separate sensor node


## Required Hardware

- [x] Microcontroller (ESP32)
- [x] Battery
- [x] Charging controller / charging module (integrated on microcontroller board)
- [x] Temperature and humidity sensor (SHT31)
- [ ] Enclosure
- [ ] Optional: RGB LED
- [ ] Optional: CO sensor for separate sensor node


## Test Strategy

- Native tests
    - Test of the application logic independent of the target hardware
    - Test of sensor processing, measurement validation and state logic using fake components
    - Test of battery level calculation and battery-related validation logic
- Embedded tests
    - Test of hardware-related functions directly on the microcontroller
    - Test of sensor integration, Wi-Fi connection and MQTT communication
    - Test of battery voltage measurement on the target hardware
- Manual system tests
    - Test of the complete wake-connect-measure-publish-sleep cycle
    - Test of MQTT integration with Mosquitto and Home Assistant
    - Long-running battery-powered operation test