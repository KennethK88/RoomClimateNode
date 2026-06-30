#include <ESP32BatteryDriver.h>
#include <Arduino.h>
#include <HardwareConfig.h>

namespace
{
    constexpr float MILLIVOLTS_TO_VOLTS = 0.001f;


    BatteryVoltage calculateBatteryVoltageFromPinMilliVolts(int adcPinVoltageMilliVolts)
    {
        return (static_cast<BatteryVoltage>(adcPinVoltageMilliVolts * MILLIVOLTS_TO_VOLTS * HardwareConfig::BATTERY_VOLTAGE_DIVIDER_FACTOR));
    }
}

void ESP32BatteryDriver::init()
{
    analogSetPinAttenuation(HardwareConfig::BATTERY_ADC_PIN, ADC_11db);
}

void ESP32BatteryDriver::readVoltage()
{
    batteryVoltage = calculateBatteryVoltageFromPinMilliVolts(analogReadMilliVolts(HardwareConfig::BATTERY_ADC_PIN));
}

BatteryVoltage ESP32BatteryDriver::getVoltage()
{
    return batteryVoltage;
}