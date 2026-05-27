#include <unity.h>
#include <DisplayController.h>
#include <array>
#include <string>

class FakeDisplayOutput : public IDisplayOutput
{
    public:
        bool cleared = false;
        bool displayed = false;
        bool sleepActive = false;
        std::array<bool, 4> lineWritten{false, false, false, false};
        std::array<std::string, 4> lines;

        void init() override {;}

        void clear() override {cleared = true;}

        void writeLine(int line, const char* text) override
        {
            if (line >= 0 && line < 4)
            {
                lineWritten[line] = true;
                lines[line] = text;
            }
        }

        void display() override {displayed = true;}
        void sleepOn() override {sleepActive = true;}
        void sleepOff() override {sleepActive = false;}
};

void test_display_current_values_and_state_normal_should_display_four_lines()
{
    // Arrange
    FakeDisplayOutput fakeDisplayOutput;
    DisplayController displayController(fakeDisplayOutput);
    Measurements measurements;

    measurements.temperature = 20.0f;
    measurements.humidity = 50.0f;
    measurements.co = 75.0f;
    SystemState systemState = SystemState::Normal;
    bool displayActive = true;

    // Act
    displayController.updateDisplay(measurements, systemState, displayActive);

    // Assert
    TEST_ASSERT_TRUE(fakeDisplayOutput.cleared);
    TEST_ASSERT_TRUE(fakeDisplayOutput.displayed);
    TEST_ASSERT_FALSE(fakeDisplayOutput.sleepActive);

    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[0]);
    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[1]);
    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[2]);
    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[3]);

    TEST_ASSERT_EQUAL_STRING("T: 20 C", fakeDisplayOutput.lines[0].c_str());
    TEST_ASSERT_EQUAL_STRING("F: 50 %", fakeDisplayOutput.lines[1].c_str());
    TEST_ASSERT_EQUAL_STRING("CO: 75 ppm", fakeDisplayOutput.lines[2].c_str());
    TEST_ASSERT_EQUAL_STRING("Status: Normal", fakeDisplayOutput.lines[3].c_str());
}

void test_display_current_values_rounded_and_state_normal_should_display_four_lines()
{
    // Arrange
    FakeDisplayOutput fakeDisplayOutput;
    DisplayController displayController(fakeDisplayOutput);
    Measurements measurements;

    measurements.temperature = 20.4f;
    measurements.humidity = 50.6f;
    measurements.co = 75.5f;
    SystemState systemState = SystemState::Normal;
    bool displayActive = true;

    // Act
    displayController.updateDisplay(measurements, systemState, displayActive);

    // Assert
    TEST_ASSERT_TRUE(fakeDisplayOutput.cleared);
    TEST_ASSERT_TRUE(fakeDisplayOutput.displayed);
    TEST_ASSERT_FALSE(fakeDisplayOutput.sleepActive);

    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[0]);
    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[1]);
    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[2]);
    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[3]);

    TEST_ASSERT_EQUAL_STRING("T: 20 C", fakeDisplayOutput.lines[0].c_str());
    TEST_ASSERT_EQUAL_STRING("F: 51 %", fakeDisplayOutput.lines[1].c_str());
    TEST_ASSERT_EQUAL_STRING("CO: 76 ppm", fakeDisplayOutput.lines[2].c_str());
    TEST_ASSERT_EQUAL_STRING("Status: Normal", fakeDisplayOutput.lines[3].c_str());
}

void test_display_current_values_and_state_warning_should_display_four_lines()
{
    // Arrange
    FakeDisplayOutput fakeDisplayOutput;
    DisplayController displayController(fakeDisplayOutput);
    Measurements measurements;

    measurements.temperature = 25.0f;
    measurements.humidity = 60.0f;
    measurements.co = 100.0f;
    SystemState systemState = SystemState::Warning;
    bool displayActive = true;

    // Act
    displayController.updateDisplay(measurements, systemState, displayActive);

    // Assert
    TEST_ASSERT_TRUE(fakeDisplayOutput.cleared);
    TEST_ASSERT_TRUE(fakeDisplayOutput.displayed);
    TEST_ASSERT_FALSE(fakeDisplayOutput.sleepActive);

    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[0]);
    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[1]);
    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[2]);
    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[3]);

    TEST_ASSERT_EQUAL_STRING("T: 25 C", fakeDisplayOutput.lines[0].c_str());
    TEST_ASSERT_EQUAL_STRING("F: 60 %", fakeDisplayOutput.lines[1].c_str());
    TEST_ASSERT_EQUAL_STRING("CO: 100 ppm", fakeDisplayOutput.lines[2].c_str());
    TEST_ASSERT_EQUAL_STRING("Status: Warning", fakeDisplayOutput.lines[3].c_str());
}

void test_display_current_values_and_state_error_should_display_four_lines()
{
    // Arrange
    FakeDisplayOutput fakeDisplayOutput;
    DisplayController displayController(fakeDisplayOutput);
    Measurements measurements;

    measurements.temperature = 30.0f;
    measurements.humidity = 70.0f;
    measurements.co = 150.0f;
    SystemState systemState = SystemState::Error;
    bool displayActive = true;

    // Act
    displayController.updateDisplay(measurements, systemState, displayActive);

    // Assert
    TEST_ASSERT_TRUE(fakeDisplayOutput.cleared);
    TEST_ASSERT_TRUE(fakeDisplayOutput.displayed);
    TEST_ASSERT_FALSE(fakeDisplayOutput.sleepActive);

    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[0]);
    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[1]);
    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[2]);
    TEST_ASSERT_TRUE(fakeDisplayOutput.lineWritten[3]);

    TEST_ASSERT_EQUAL_STRING("T: 30 C", fakeDisplayOutput.lines[0].c_str());
    TEST_ASSERT_EQUAL_STRING("F: 70 %", fakeDisplayOutput.lines[1].c_str());
    TEST_ASSERT_EQUAL_STRING("CO: 150 ppm", fakeDisplayOutput.lines[2].c_str());
    TEST_ASSERT_EQUAL_STRING("Status: Error", fakeDisplayOutput.lines[3].c_str());
}

void test_update_display_should_enter_sleep_mode_when_display_inactive()
{
    // Arrange
    FakeDisplayOutput fakeDisplayOutput;
    DisplayController displayController(fakeDisplayOutput);
    Measurements measurements;

    measurements.temperature = 30.0f;
    measurements.humidity = 70.0f;
    measurements.co = 150.0f;
    SystemState systemState = SystemState::Error;
    bool displayActive = false;

    // Act
    displayController.updateDisplay(measurements, systemState, displayActive);

    // Assert
    TEST_ASSERT_FALSE(fakeDisplayOutput.cleared);
    TEST_ASSERT_FALSE(fakeDisplayOutput.displayed);
    TEST_ASSERT_TRUE(fakeDisplayOutput.sleepActive);

    TEST_ASSERT_FALSE(fakeDisplayOutput.lineWritten[0]);
    TEST_ASSERT_FALSE(fakeDisplayOutput.lineWritten[1]);
    TEST_ASSERT_FALSE(fakeDisplayOutput.lineWritten[2]);
    TEST_ASSERT_FALSE(fakeDisplayOutput.lineWritten[3]);
}