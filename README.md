[![Firmware Builds](https://github.com/KennethK88/RoomClimateNode/actions/workflows/build.yml/badge.svg?branch=main)](https://github.com/KennethK88/RoomClimateNode/actions/workflows/build.yml)
[![Native Tests](https://github.com/KennethK88/RoomClimateNode/actions/workflows/test.yml/badge.svg?branch=main)](https://github.com/KennethK88/RoomClimateNode/actions/workflows/test.yml)
[![Build Documentation](https://github.com/KennethK88/RoomClimateNode/actions/workflows/docs.yml/badge.svg?branch=main)](https://github.com/KennethK88/RoomClimateNode/actions/workflows/docs.yml)

# RoomClimateNode


## Project Goal

The goal of this project is to develop a compact, battery-powered ESP32-based room climate monitoring node. The node measures temperature, relative humidity, and battery level and transmits the collected data via Wi-Fi and MQTT to a Home Assistant environment. The project focuses on embedded C++ development, modular software architecture, reusable components, testability, and low-power operation using ESP32 deep sleep.


## Key Features

- Temperature and humidity monitoring using the SHT31 sensor
- Battery voltage monitoring and battery level estimation
- Wi-Fi and MQTT communication with Home Assistant
- Low-power operation using ESP32 deep sleep
- MQTT-controlled OTA firmware update windows
- Support for LOLIN D32 and LOLIN C3 Pico
- Modular C++17 architecture with reusable components


## Current Status

The RoomClimateNode is operational and integrated into Home Assistant. Multiple battery-powered nodes are currently deployed and running on both LOLIN D32 and LOLIN C3 Pico hardware. Further development and known limitations are documented in the [Project Overview](docs/ProjectOverview.md) and [GitHub Issues](https://github.com/KennethK88/RoomClimateNode/issues).


## Technologies

- C++17
- PlatformIO
- ESP32 / ESP32-C3
- SHT31
- Wi-Fi / MQTT
- Mosquitto
- Home Assistant
- Unity Test Framework
- GitHub Actions
- Doxygen
- PlantUML


## Documentation

- [Project Overview](docs/ProjectOverview.md)
- [Home Assistant Integration](docs/home-assistant/README.md)
- System Architecture: [Diagram](docs/SystemArchitecture.svg) | [PlantUML Source](docs/SystemArchitecture.puml)
- Class Diagram: [Diagram](docs/ClassDiagram.svg) | [PlantUML Source](docs/ClassDiagram.puml)
- Measurement Sequence Diagram: [Diagram](docs/MeasurementSequenceDiagram.svg) | [PlantUML Source](docs/MeasurementSequenceDiagram.puml)
- OTA Sequence Diagram: [Diagram](docs/OtaSequenceDiagram.svg) | [PlantUML Source](docs/OtaSequenceDiagram.puml)
- [Hardware Wiring](docs/Wiring.md)
- [Git Conventions](docs/GitConventions.md)