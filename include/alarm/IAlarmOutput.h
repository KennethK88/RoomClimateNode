#pragma once

class IAlarmOutput
{
    public:
        virtual ~IAlarmOutput() = default;
        virtual void activate() = 0;
        virtual void deactivate() = 0;
};