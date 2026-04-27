#include <Arduino.h>

namespace HardwareConfig
{
    constexpr int BUZZER_DIGITAL_PIN = PIN_D2;
    constexpr int LED_DIGITAL_PIN = PIN_D4;
    constexpr int THERMISTOR_ANALOG_PIN = PIN_A0;
    constexpr int HUMIDITY_DRIVER_PIN = PIN_D7;
    constexpr int HUMIDITY_DRIVER_TYPE = 11;
    constexpr int DISTANCE_DRIVER_TRIGGER_PIN = PIN_D9;
    constexpr int DISTANCE_DRIVER_ECHO_PIN = PIN_D10;
}