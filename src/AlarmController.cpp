#include "AlarmController.h"

void AlarmController::updateAlarm(SystemState systemState)
{
    if(systemState == SystemState::Warning) alarmActive = true;
    else alarmActive = false;
}

bool AlarmController::isAlarmActive() const
{
    return alarmActive;
}