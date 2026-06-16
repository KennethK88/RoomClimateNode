#include <ESP32BatteryDriver.h>

namespace
{
    constexpr float BATTERY_VOLTAGE_DIVIDER_FACTOR = 2.0f;
    constexpr float ADC_MAX_VALUE = 4095.0f;
    constexpr float ADC_REFERENCE_VOLTAGE = 3.3f;

    float calculateAdcPinVoltage(int adcRawValue)
    {
        return (static_cast<float>(adcRawValue) / ADC_MAX_VALUE * ADC_REFERENCE_VOLTAGE);
    }

    BatteryVoltage calculateBatteryVoltage(float adcPinVoltage)
    {
        return (static_cast<BatteryVoltage>(adcPinVoltage * BATTERY_VOLTAGE_DIVIDER_FACTOR));
    }
}

void ESP32BatteryDriver::init()
{
    //
}

void ESP32BatteryDriver::readVoltage()
{
    batteryVoltage = BatteryConstants::BATTERY_VOLTAGE_NOT_INITIALIZED; // Adc raw value needed
}

BatteryVoltage ESP32BatteryDriver::getVoltage()
{
    return batteryVoltage;
}