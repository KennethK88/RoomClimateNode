#pragma once
#include <ISensorDriver.h>

class DistanceDriver : public ISensorDriver
{
    private:
        unsigned long readRawValue();
        float convertRawValueToDistance(unsigned long rawValue); 
    
    public:
        DistanceDriver() = default;
        void init() override;
        float getValue() override;
};