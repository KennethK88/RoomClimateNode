# RoomClimateNode – Wiring

This document describes the hardware connections for the supported
RoomClimateNode platforms:

- LOLIN D32 (ESP32)
- LOLIN C3 Pico (ESP32-C3)

Both platforms use an SHT31 temperature and humidity sensor
and a rechargeable LiPo battery.

## Pin Assignments

| Function | LOLIN D32 | LOLIN C3 Pico |
|----------|-----------|--------------|
| SHT31 VCC | 3V3 | 3V3 |
| SHT31 GND | GND | GND |
| SHT31 SDA | GPIO14 | GPIO8 |
| SHT31 SCL | GPIO13 | GPIO10 |
| Battery ADC | GPIO35 | GPIO3 |

## Battery

The LiPo battery supplies the microcontroller through its board-specific battery connection. Battery voltage is monitored through the board's ADC measurement circuitry. Both platforms use a configured battery voltage divider factor of 2.0.

## General Notes

- The SHT31 communicates via I2C.
- The SHT31 must support 3.3 V operation.
- Verify battery connector polarity before connecting a LiPo battery.
- Board-specific pin assignments are defined in:
  - `HardwareConfigD32.h`
  - `HardwareConfigC3Pico.h`
- The appropriate configuration is selected at compile time
  through `HardwareConfig.h`.