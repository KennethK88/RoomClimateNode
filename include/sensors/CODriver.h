#pragma once
#include <ISensorDriver.h>

class CODriver : public ISensorDriver
{
    private: 
    
    public:
        CODriver() = default;
        void init() override;
        float getValue() override;
};