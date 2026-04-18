#pragma once
#include <vector>
#include <IAlarmOutput.h>

class CompositeAlarmOutput : public IAlarmOutput
{
    private:
        std::vector<IAlarmOutput*> alarmOutputs;

    public:
        CompositeAlarmOutput() = default;
        void add(IAlarmOutput* alarmOutput);
        void activate() override;
        void deactivate() override;
};