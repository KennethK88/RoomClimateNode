#include <unity.h>
#include <LedController.h>

class FakeLed : public ILedOutput
{
    public:
        bool isLedOn = false;
        void init() override {;}
        void turnOn() override {isLedOn = true;}
        void turnOff() override {isLedOn = false;}
};

void test_system_state_normal_only_normal_led_should_be_turned_on()
{
    // Arrange
    FakeLed fakeNormalLed;
    FakeLed fakeWarningLed;
    FakeLed fakeErrorLed;
    LedController ledController(fakeNormalLed, fakeWarningLed, fakeErrorLed);
    SystemState systemState = SystemState::Normal;

    // Act
    ledController.updateLeds(systemState);

    // Assert
    TEST_ASSERT_TRUE(fakeNormalLed.isLedOn);
    TEST_ASSERT_FALSE(fakeWarningLed.isLedOn);
    TEST_ASSERT_FALSE(fakeErrorLed.isLedOn);
}

void test_system_state_warning_only_warning_led_should_be_turned_on()
{
    // Arrange
    FakeLed fakeNormalLed;
    FakeLed fakeWarningLed;
    FakeLed fakeErrorLed;
    LedController ledController(fakeNormalLed, fakeWarningLed, fakeErrorLed);
    SystemState systemState = SystemState::Warning;

    // Act
    ledController.updateLeds(systemState);

    // Assert
    TEST_ASSERT_FALSE(fakeNormalLed.isLedOn);
    TEST_ASSERT_TRUE(fakeWarningLed.isLedOn);
    TEST_ASSERT_FALSE(fakeErrorLed.isLedOn);
}

void test_system_state_error_only_error_led_should_be_turned_on()
{
    // Arrange
    FakeLed fakeNormalLed;
    FakeLed fakeWarningLed;
    FakeLed fakeErrorLed;
    LedController ledController(fakeNormalLed, fakeWarningLed, fakeErrorLed);
    SystemState systemState = SystemState::Error;

    // Act
    ledController.updateLeds(systemState);

    // Assert
    TEST_ASSERT_FALSE(fakeNormalLed.isLedOn);
    TEST_ASSERT_FALSE(fakeWarningLed.isLedOn);
    TEST_ASSERT_TRUE(fakeErrorLed.isLedOn);
}