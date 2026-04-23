#pragma once
#include <IAlarmOutput.h>

class BuzzerDriver : public IAlarmOutput
{
    public:
        BuzzerDriver() = default;
        void init();
        void activate() override;
        void deactivate() override;
};