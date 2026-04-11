#pragma once
#include "alarm/IAlarmOutput.h"

class BuzzerDriver : public IAlarmOutput
{
    public:
        BuzzerDriver() = default;
        void init();
        void activate() override;
        void deactivate() override;
};