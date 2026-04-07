#include "LedDriver.h"
#include <Arduino.h>
#include "HardwareConfig.h"

void LedDriver::init()
{
    pinMode(HardwareConfig::LED_PIN, OUTPUT);
}

void LedDriver::activate()
{
    digitalWrite(HardwareConfig::LED_PIN, HIGH);
}

void LedDriver::deactivate()
{
    digitalWrite(HardwareConfig::LED_PIN, LOW);
}