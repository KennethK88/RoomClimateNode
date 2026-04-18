#pragma once
#include <IAlarmOutput.h>

class LedDriver : public IAlarmOutput
{
    public:
        LedDriver() = default;
        void init();
        void activate() override;
        void deactivate() override;
};