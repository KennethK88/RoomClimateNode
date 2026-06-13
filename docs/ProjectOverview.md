# Project Overview: AirMonitorController

## Project Goal

The goal of this project is to develop a compact microcontroller-based room climate node. The node measures temperature and humidity values, processes and validates the measurement data locally, and transmits it wirelessly to a smart home system. Due to the fireplace in the living room, an optional separate CO sensor node is planned for this room.


## Current Status

Temperature and humidity are currently measured using an SHT31 sensor. The measurement values are transmitted via WiFi and MQTT to a Mosquitto broker running on a Raspberry Pi.


## Planned Functional Scope

- [ ] Measure values
    - [x] Room temperature in °C
    - [x] Relative humidity in %
    - [ ] Battery level in %
- [ ] Validate measured values
    - [x] Room temperature in °C
    - [x] Relative humidity in %
    - [ ] Battery level in %
- [ ] Provide measured values via WiFi/MQTT
    - [x] Room temperature in °C
    - [x] Relative humidity in %
    - [ ] Battery level in % 
- [ ] Put the microcontroller into deep sleep between measurement cycles
- [ ] Enable firmware updates via over-the-air update (OTA)
- [ ] Enable battery-powered operation
- [ ] Optional: Display system states using an RGB status LED
    - [ ] Indicate low battery level
    - [ ] Indicate implausible measured values
    - [ ] Indicate failed WiFi/MQTT connection
    - [ ] Indicate fully charged battery while connected to the charger
- [ ] Optional: Measure CO values using a separate sensor node


## Required Hardware

- [ ] Microcontroller (ESP32)
- [ ] Battery
- [ ] Charging controller / charging module
- [x] Temperature and humidity sensor (SHT31)
- [x] RGB LED
- [ ] Enclosure
- [ ] Optional: CO sensor for separate sensor node


## Test Strategy

- Native tests
    - Test of the application logic independent of the target hardware
    - Test of sensor processing, measurement validation and state logic using fake components
- Embedded tests
    - Test of hardware-related functions directly on the microcontroller
    - Test of sensor integration, Wi-Fi connection and MQTT communication