#include "sensors/DistanceDriver.h"
#include <HardwareConfig.h>

namespace
{
    constexpr float SOUND_SPEED_CM_PER_US = 0.0343f;
}

void DistanceDriver::init()
{
    // TODO: Hardwarekomponente anbinden
    pinMode(HardwareConfig::DISTANCE_DRIVER_TRIGGER_PIN, OUTPUT);
    pinMode(HardwareConfig::DISTANCE_DRIVER_ECHO_PIN, INPUT);
    digitalWrite(HardwareConfig::DISTANCE_DRIVER_TRIGGER_PIN, LOW);
}

unsigned long DistanceDriver::readRawValue()
{
    // 1. Trigger-Pin kurz auf LOW setzen, um einen sauberen Impuls zu sichern
    digitalWrite(HardwareConfig::DISTANCE_DRIVER_TRIGGER_PIN, LOW);
    delayMicroseconds(2);

    // 2. Den Sensor anweisen, für 10 Mikrosekunden ein Signal zu senden
    digitalWrite(HardwareConfig::DISTANCE_DRIVER_TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(HardwareConfig::DISTANCE_DRIVER_TRIGGER_PIN, LOW);

    // 3. Zeit messen, bis das Echo zurückkommt (in Mikrosekunden)
    return pulseIn(HardwareConfig::DISTANCE_DRIVER_ECHO_PIN, HIGH, 30000); // 30000 entsprechen 5 m
}

float DistanceDriver::convertRawValueToDistance(unsigned long rawValue)
{
    // 4. Distanz berechnen
    // Formel: Entfernung = (Zeit / 2) * Schallgeschwindigkeit (0.0343 cm/us)
    return (rawValue * SOUND_SPEED_CM_PER_US / 2.0f);
}

float DistanceDriver::getValue()
{
    unsigned long rawValue = readRawValue();
    return convertRawValueToDistance(rawValue);
}