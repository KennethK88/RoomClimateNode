#include "alarm/LedDriver.h"
#include <Arduino.h>
#include "utils/HardwareConfig.h"

void LedDriver::init()
{
    pinMode(HardwareConfig::LED_DIGITAL_PIN, OUTPUT);
}

void LedDriver::activate()
{
    digitalWrite(HardwareConfig::LED_DIGITAL_PIN, HIGH);
}

void LedDriver::deactivate()
{
    digitalWrite(HardwareConfig::LED_DIGITAL_PIN, LOW);
}