#include <BuzzerDriver.h>
#include <Arduino.h>
#include <HardwareConfig.h>

void BuzzerDriver::init()
{
    pinMode(HardwareConfig::BUZZER_DIGITAL_PIN, OUTPUT);
}

void BuzzerDriver::activate()
{
    digitalWrite(HardwareConfig::BUZZER_DIGITAL_PIN, HIGH);
}

void BuzzerDriver::deactivate()
{
    digitalWrite(HardwareConfig::BUZZER_DIGITAL_PIN, LOW);
}