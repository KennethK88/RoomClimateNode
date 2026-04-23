#include <unity.h>
#include <AlarmController.h>

class FakeAlarmOutput : public IAlarmOutput
{
    public:
        bool fakeAlarmActive = false;
        void activate() override {fakeAlarmActive = true;}
        void deactivate() override {fakeAlarmActive = false;}
};

void test_state_is_normal_alarm_should_be_inactive()
{
    // Arrange
    FakeAlarmOutput fakeAlarmOutput;
    AlarmController alarmController(fakeAlarmOutput);
    SystemState systemState = SystemState::Normal;

    // Act
    alarmController.updateAlarm(systemState);

    // Assert
    TEST_ASSERT_FALSE(alarmController.isAlarmActive());
    TEST_ASSERT_FALSE(fakeAlarmOutput.fakeAlarmActive);
}

void test_state_is_error_alarm_should_be_inactive()
{
    // Arrange
    FakeAlarmOutput fakeAlarmOutput;
    AlarmController alarmController(fakeAlarmOutput);
    SystemState systemState = SystemState::Error;

    // Act
    alarmController.updateAlarm(systemState);

    // Assert
    TEST_ASSERT_FALSE(alarmController.isAlarmActive());
    TEST_ASSERT_FALSE(fakeAlarmOutput.fakeAlarmActive);
}

void test_state_is_warning_alarm_should_be_active()
{
    // Arrange
    FakeAlarmOutput fakeAlarmOutput;
    AlarmController alarmController(fakeAlarmOutput);
    SystemState systemState = SystemState::Warning;

    // Act
    alarmController.updateAlarm(systemState);

    // Assert
    TEST_ASSERT_TRUE(alarmController.isAlarmActive());
    TEST_ASSERT_TRUE(fakeAlarmOutput.fakeAlarmActive);
}