[![PlatformIO Native Tests and Build](https://github.com/KennethK88/AirMonitorController/actions/workflows/main.yml/badge.svg?branch=main)](https://github.com/KennethK88/AirMonitorController/actions/workflows/main.yml)
[![Deploy Documentation](https://github.com/KennethK88/AirMonitorController/actions/workflows/docs.yml/badge.svg?branch=main)](https://github.com/KennethK88/AirMonitorController/actions/workflows/docs.yml)


# RoomClimateNode

## Ziel 

Ziel des Projekts ist die Entwicklung eines kompakten Raumklima-Knotens auf Mikrocontrollerbasis. Der Knoten erfasst Temperatur- und Luftfeuchtigkeitswerte, verarbeitet und validiert die Messdaten lokal und überträgt sie drahtlos an ein Smart-Home-System.


## Aktueller Stand

Aktuell erfolgt die Messung von Temperatur und Luftfeuchtigkeit über einen SHT31-Sensor. Die Messwerte werden über WLAN per MQTT an einen Mosquitto-Broker auf einem Raspberry Pi übertragen.


## Technologien

- C/C++
- PlatformIO
- Testframework Unity
- GitHub Actions
- Arduino Uno R4 WiFi
- SHT31
- WLAN / MQTT
- Mosquitto
- Home Assistant


## Weitere Dokumentation

- [Projektübersicht](docs/Projektübersicht.md)
- [Klassendiagramm](docs/Klassen.puml)