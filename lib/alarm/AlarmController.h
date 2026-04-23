#pragma once
#include <SystemState.h>
#include <IAlarmOutput.h>

class AlarmController
{
    private:
        bool alarmActive = false;
        IAlarmOutput& alarmOutput;

    public:
        AlarmController(IAlarmOutput& alarmOutput) : alarmOutput(alarmOutput) {};
        void updateAlarm(SystemState systemState);
        bool isAlarmActive() const;
};