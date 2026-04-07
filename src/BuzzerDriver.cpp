#include "BuzzerDriver.h"
#include <Arduino.h>
#include "HardwareConfig.h"

void BuzzerDriver::initBuzzer()
{
    pinMode(HardwareConfig::BUZZER_PIN, OUTPUT);
}

void BuzzerDriver::activateBuzzer()
{
    digitalWrite(HardwareConfig::BUZZER_PIN, HIGH);
}

void BuzzerDriver::deactivateBuzzer()
{
    digitalWrite(HardwareConfig::BUZZER_PIN, LOW);
}