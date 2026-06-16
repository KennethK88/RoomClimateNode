#include <unity.h>
#include <StateMachine.h>

void test_all_validations_valid_state_should_be_normal()
{
    // Arrange
    ValidationResults validationResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = true;
    validationResults.batteryLevelValid = true;

    // Act
    SystemState systemState = stateMachine.calculateState(validationResults);

    // Assert
    TEST_ASSERT_EQUAL(SystemState::Normal, systemState);
}

void test_temperature_invalid_state_should_be_error()
{
    // Arrange
    ValidationResults validationResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = false;
    validationResults.humidityValid = true;
    validationResults.batteryLevelValid = true;
    
    // Act
    SystemState systemState = stateMachine.calculateState(validationResults);

    // Assert
    TEST_ASSERT_EQUAL(SystemState::Error, systemState);
}

void test_humidity_invalid_state_should_be_error()
{
    // Arrange
    ValidationResults validationResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = false;
    validationResults.batteryLevelValid = true;
    
    // Act
    SystemState systemState = stateMachine.calculateState(validationResults);

    // Assert
    TEST_ASSERT_EQUAL(SystemState::Error, systemState);
}

void test_battery_level_invalid_state_should_be_error()
{
    // Arrange
    ValidationResults validationResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = true;
    validationResults.batteryLevelValid = false;
    
    // Act
    SystemState systemState = stateMachine.calculateState(validationResults);

    // Assert
    TEST_ASSERT_EQUAL(SystemState::Error, systemState);
}