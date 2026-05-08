#include <LedDriver.h>
#include <Arduino.h>

void LedDriver::init()
{
    pinMode(pinNumber, OUTPUT);
}

void LedDriver::turnOn()
{
    digitalWrite(pinNumber, HIGH);
}

void LedDriver::turnOff()
{
    digitalWrite(pinNumber, LOW);
}