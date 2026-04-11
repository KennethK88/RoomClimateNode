#include "BuzzerDriver.h"
#include <Arduino.h>
#include "HardwareConfig.h"

void BuzzerDriver::init()
{
    pinMode(HardwareConfig::BUZZER_PIN, OUTPUT);
}

void BuzzerDriver::activate()
{
    digitalWrite(HardwareConfig::BUZZER_PIN, HIGH);
}

void BuzzerDriver::deactivate()
{
    digitalWrite(HardwareConfig::BUZZER_PIN, LOW);
}