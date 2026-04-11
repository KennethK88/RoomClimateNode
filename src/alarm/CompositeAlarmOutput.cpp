#include "CompositeAlarmOutput.h"

void CompositeAlarmOutput::add(IAlarmOutput* alarmOutput)
{
    if(alarmOutput != nullptr) alarmOutputs.push_back(alarmOutput);
    // TODO: Mögliche doppelte Einträge abfangen
}

void CompositeAlarmOutput::activate()
{
    for(IAlarmOutput* alarmOutput : alarmOutputs) alarmOutput->activate();
}

void CompositeAlarmOutput::deactivate()
{
    for(IAlarmOutput* alarmOutput : alarmOutputs) alarmOutput->deactivate();
}