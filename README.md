[![Firmware Builds](https://github.com/KennethK88/RoomClimateNode/actions/workflows/build.yml/badge.svg?branch=main)](https://github.com/KennethK88/RoomClimateNode/actions/workflows/build.yml)
[![Native Tests](https://github.com/KennethK88/RoomClimateNode/actions/workflows/test.yml/badge.svg?branch=main)](https://github.com/KennethK88/RoomClimateNode/actions/workflows/test.yml)
[![Build Documentation](https://github.com/KennethK88/RoomClimateNode/actions/workflows/docs.yml/badge.svg?branch=main)](https://github.com/KennethK88/RoomClimateNode/actions/workflows/docs.yml)

# RoomClimateNode

## Project Goal

The goal of this project is to develop a compact, battery-powered ESP32-based room climate monitoring node. The node measures temperature, relative humidity, and battery level and transmits the collected data via Wi-Fi and MQTT to a Home Assistant environment. The project focuses on embedded C++ development, modular software architecture, reusable components, testability, and low-power operation using ESP32 deep sleep.


## Current Status

The RoomClimateNode is operational and integrated into Home Assistant.

Temperature and humidity are measured using an SHT31 sensor. Battery voltage is monitored and converted into a battery level percentage. Measurements are published via Wi-Fi and MQTT to a Mosquitto broker and made available in Home Assistant. The node operates on a periodic wake-connect-measure-publish-sleep cycle with a configured deep sleep interval of 15 minutes. Firmware updates are supported through MQTT-controlled OTA maintenance windows. Firmware version information and OTA status are also published via MQTT. The firmware supports both the LOLIN D32 and LOLIN C3 Pico. Battery-powered operation has been successfully tested, and multiple
nodes are in use.

Further development and known limitations are documented in the Project Overview and GitHub Issues.


## Technologies

- C++ / Arduino Framework
- PlatformIO
- Unity Test Framework
- GitHub Actions
- ESP32 / ESP32-C3
- SHT31
- Wi-Fi / MQTT
- Mosquitto
- Home Assistant
- Doxygen
- PlantUML


## Documentation

- [Project Overview](docs/ProjectOverview.md)
- [System Architecture](docs/SystemArchitecture.puml)
- [Class Diagram](docs/ClassDiagram.puml)
- [Measurement Sequence Diagram](docs/MeasurementSequenceDiagram.puml)
- [OTA Sequence Diagram](docs/OtaSequenceDiagram.puml)
- [Hardware Wiring](docs/Wiring.md)
- [Git Conventions](docs/GitConventions.md)