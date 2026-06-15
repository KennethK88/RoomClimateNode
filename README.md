[![PlatformIO Native Tests and Build](https://github.com/KennethK88/AirMonitorController/actions/workflows/main.yml/badge.svg?branch=main)](https://github.com/KennethK88/AirMonitorController/actions/workflows/main.yml)
[![Deploy Documentation](https://github.com/KennethK88/AirMonitorController/actions/workflows/docs.yml/badge.svg?branch=main)](https://github.com/KennethK88/AirMonitorController/actions/workflows/docs.yml)


# RoomClimateNode

## Project Goal 

The goal of this project is to develop a compact microcontroller-based room climate node. The node measures temperature and humidity values, processes and validates the measurement data locally, and transmits it wirelessly to a smart home system.


## Current Status

Temperature and humidity are currently measured using an SHT31 sensor. The measurement values are transmitted via Wi-Fi and MQTT to a Mosquitto broker running on a Raspberry Pi.


## Technologies

- C/C++
- PlatformIO
- Testframework Unity
- GitHub Actions
- Arduino Uno R4 WiFi
- SHT31
- WiFi / MQTT
- Mosquitto
- Home Assistant


## Further Documentation

- [Project overview](docs/ProjectOverview.md)
- [System architecture](docs/SystemArchitecture.puml)
- [Class diagram](docs/ClassDiagram.puml)