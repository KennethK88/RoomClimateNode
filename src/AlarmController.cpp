#include "AlarmController.h"

void AlarmController::updateAlarm(SystemState systemState)
{
    if(systemState == SystemState::Warning) 
    {
        alarmActive = true;
        alarmOutput.activate();
    }
    else 
    {
        alarmActive = false;
        alarmOutput.deactivate();
    }
}

bool AlarmController::isAlarmActive() const
{
    return alarmActive;
}