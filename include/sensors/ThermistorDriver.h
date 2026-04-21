#pragma once
#include <ISensorDriver.h>

class ThermistorDriver : public ISensorDriver
{
    private: 
        int readRawValue();
        float convertRawValueToTemperature(int rawValue);
    
    public:
        ThermistorDriver() = default;
        void init() override;
        float getValue() override;
};