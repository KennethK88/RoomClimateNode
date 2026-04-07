#pragma once
#include "SystemState.h"
#include "BuzzerDriver.h"

class AlarmController
{
    private:
        bool alarmActive = false;
        BuzzerDriver buzzerDriver;

    public:
        AlarmController() = default;
        void init();
        void updateAlarm(SystemState systemState);
        bool isAlarmActive() const;
};