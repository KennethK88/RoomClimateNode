#include <unity.h>
#include <StateMachine.h>

void test_all_validations_valid_and_all_thresholds_ok_state_should_be_normal()
{
    // Arrange
    ValidationResults validationResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = true;

    // Act
    SystemState systemState = stateMachine.calculateState(validationResults);

    // Assert
    TEST_ASSERT_TRUE(systemState == SystemState::Normal);
}

void test_temperature_invalid_and_all_thresholds_ok_state_should_be_error()
{
    // Arrange
    ValidationResults validationResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = false;
    validationResults.humidityValid = true;
    
    // Act
    SystemState systemState = stateMachine.calculateState(validationResults);

    // Assert
    TEST_ASSERT_TRUE(systemState == SystemState::Error);
}

void test_humidity_invalid_and_all_thresholds_ok_state_should_be_error()
{
    // Arrange
    ValidationResults validationResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = false;
    
    // Act
    SystemState systemState = stateMachine.calculateState(validationResults);

    // Assert
    TEST_ASSERT_TRUE(systemState == SystemState::Error);
}