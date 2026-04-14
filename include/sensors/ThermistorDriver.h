#pragma once

class ThermistorDriver
{
    private: 
        int readRawValue();
        float convertRawValueToTemperature(int rawValue);
    
    public:
        ThermistorDriver() = default;
        void init();
        float getTemperature();
};