#pragma once
#include "alarm/IAlarmOutput.h"

class LedDriver : public IAlarmOutput
{
    public:
        LedDriver() = default;
        void init();
        void activate() override;
        void deactivate() override;
};