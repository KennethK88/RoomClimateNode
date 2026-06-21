#include <ESP32BatteryDriver.h>
#include <Arduino.h>
#include <HardwareConfig.h>

namespace
{
    constexpr float MILLIVOLTS_TO_VOLTS = 0.0001f;


    BatteryVoltage calculateBatteryVoltageFromPinMilliVolts(int adcPinVoltageMilliVolts)
    {
        return (static_cast<BatteryVoltage>(adcPinVoltageMilliVolts * MILLIVOLTS_TO_VOLTS * HardwareConfig::BATTERY_VOLTAGE_DIVIDER_FACTOR));
    }
}

void ESP32BatteryDriver::init()
{
    #ifdef ARDUINO_ARCH_ESP32
        analogSetPinAttenuation(HardwareConfig::BATTERY_ADC_PIN, ADC_11db);
    #else
        //
    #endif
}

void ESP32BatteryDriver::readVoltage()
{
    #ifdef ARDUINO_ARCH_ESP32
        batteryVoltage = calculateBatteryVoltageFromPinMilliVolts(analogReadMilliVolts(HardwareConfig::BATTERY_ADC_PIN));
    #else
        batteryVoltage = BatteryConstants::BATTERY_VOLTAGE_NOT_INITIALIZED;
    #endif
}

BatteryVoltage ESP32BatteryDriver::getVoltage()
{
    return batteryVoltage;
}