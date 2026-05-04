#include <ThermistorDriver.h>
#include "utils/HardwareConfig.h"
#include <Arduino.h>

void ThermistorDriver::init()
{
    pinMode(HardwareConfig::THERMISTOR_ANALOG_PIN, INPUT);
}

int ThermistorDriver::readRawValue()
{
    return analogRead(HardwareConfig::THERMISTOR_ANALOG_PIN); 
}

float ThermistorDriver::convertRawValueToTemperature(int rawValue)
{
    // TODO: const Werte & Berechnung ggf. auslagern
    const float R1 = 10000.0; // 10kOhm Widerstand
    const float nominalResistance = 10000.0; // Widerstand des NTC
    const float nominalTemperature = 25.0; // Temperatur fuer Nennwiderstand
    const float bCoefficient = 3950.0; // B-Wert des NTC

    // Widerstand des NTC berechnen
    float resistance = R1 * (1023.0 / rawValue - 1.0); // TODO: Nulldivision absichern
    
    // Steinhart-Hart Gleichung
    float tempK;
    tempK = log(resistance / nominalResistance) / bCoefficient;
    tempK += 1.0 / (nominalTemperature + 273.15);
    tempK = 1.0 / tempK;
    
    return tempK - 273.15; // Celsius
}

float ThermistorDriver::getValue()
{
    int rawValue = readRawValue();
    return convertRawValueToTemperature(rawValue);
}