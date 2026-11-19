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

## Hardware References

The following official manufacturer documentation provides additional technical details, datasheets, and board schematics.

| Hardware | Documentation |
|----------|---------------|
| LOLIN D32 | [Board Documentation & Schematic](https://www.wemos.cc/en/latest/d32/d32.html) |
| LOLIN C3 Pico | [Board Documentation & Schematic](https://docs.wemos.cc/en/latest/c3/c3_pico.html) |
| ESP32 | [ESP32 Series Datasheet](https://documentation.espressif.com/esp32_datasheet_en.html) |
| ESP32-C3 | [ESP32-C3 Series Datasheet](https://documentation.espressif.com/esp32-c3_datasheet_en.html) |
| SHT31 | [Sensirion SHT3x-DIS Datasheet (PDF)](https://sensirion.com/media/documents/213E6A3B/63A5A569/Datasheet_SHT3x_DIS.pdf) |