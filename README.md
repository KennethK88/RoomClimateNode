[![PlatformIO Native Tests and Build](https://github.com/KennethK88/AirMonitorController/actions/workflows/main.yml/badge.svg?branch=main)](https://github.com/KennethK88/AirMonitorController/actions/workflows/main.yml)
[![Deploy Documentation](https://github.com/KennethK88/AirMonitorController/actions/workflows/docs.yml/badge.svg?branch=main)](https://github.com/KennethK88/AirMonitorController/actions/workflows/docs.yml)


# RoomClimateNode

## Project Goal 

The goal of this project is to develop a compact, battery-powered microcontroller-based room climate node. The node measures temperature and humidity values, processes and validates the measurement data locally, and transmits it wirelessly via MQTT to a smart home system. The project focuses on embedded C/C++ development, modular software architecture, testability, CI integration and low-power operation using ESP32 deep sleep.


## Current Status

Temperature and humidity are measured using an SHT31 sensor. The measurement values are transmitted via Wi-Fi and MQTT to a Mosquitto broker and are consumed by Home Assistant. The current ESP32 implementation supports a wake-measure-publish-sleep cycle using deep sleep. The node wakes up periodically, connects to Wi-Fi and MQTT, reads the sensor and battery level, publishes the measurements and returns to deep sleep. A first battery runtime test is currently in progress.


## Technologies

- C/C++
- PlatformIO
- Testframework Unity
- GitHub Actions
- ESP32
- SHT31
- WiFi / MQTT
- Mosquitto
- Home Assistant


## Further Documentation

- [Project overview](docs/ProjectOverview.md)
- [System architecture](docs/SystemArchitecture.puml)
- [Class diagram](docs/ClassDiagram.puml)