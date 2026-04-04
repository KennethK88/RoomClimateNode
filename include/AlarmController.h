#pragma once
#include "SystemState.h"

class AlarmController
{
    private:
        bool alarmActive = false;

    public:
        AlarmController() = default;
        void updateAlarm(SystemState systemState);
        bool isAlarmActive() const;
};