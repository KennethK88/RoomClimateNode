#pragma once
#include <ISensorDriver.h>

class DistanceDriver : public ISensorDriver
{
    private: 
    
    public:
        DistanceDriver() = default;
        void init() override;
        float getValue() override;
};