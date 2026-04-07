#include "AlarmController.h"

void AlarmController::init()
{
    buzzerDriver.initBuzzer();
}

void AlarmController::updateAlarm(SystemState systemState)
{
    if(systemState == SystemState::Warning) 
    {
        alarmActive = true;
        buzzerDriver.activateBuzzer();
    }
    else 
    {
        alarmActive = false;
        buzzerDriver.deactivateBuzzer();
    }
}

bool AlarmController::isAlarmActive() const
{
    return alarmActive;
}