#pragma once
#include <IBatteryDriver.h>
#include <Types.h>
#include <BatteryConstants.h>

class ESP32BatteryDriver : public IBatteryDriver
{
    private:
        BatteryVoltage batteryVoltage = BatteryConstants::BATTERY_VOLTAGE_NOT_INITIALIZED;
        
    public:
        ESP32BatteryDriver() = default;
        void init() override;
        void readVoltage() override;
        BatteryVoltage getVoltage() override;
};