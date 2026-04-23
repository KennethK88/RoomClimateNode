#include <unity.h>
#include <StateMachine.h>

void test_all_validations_valid_and_all_thresholds_ok_state_should_be_normal()
{
    // Arrange
    ValidationResults validationResults;
    ThresholdResults thresholdResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = true;
    validationResults.coValid = true;

    thresholdResults.temperatureTooHigh = false;
    thresholdResults.temperatureTooLow = false;
    thresholdResults.humidityTooHigh = false;
    thresholdResults.humidityTooLow = false;
    thresholdResults.coTooHigh = false;
    
    // Act
    SystemState systemState = stateMachine.calculateState(validationResults, thresholdResults);

    // Assert
    TEST_ASSERT_TRUE(systemState == SystemState::Normal);
}

void test_temperature_invalid_and_all_thresholds_ok_state_should_be_error()
{
    // Arrange
    ValidationResults validationResults;
    ThresholdResults thresholdResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = false;
    validationResults.humidityValid = true;
    validationResults.coValid = true;

    thresholdResults.temperatureTooHigh = false;
    thresholdResults.temperatureTooLow = false;
    thresholdResults.humidityTooHigh = false;
    thresholdResults.humidityTooLow = false;
    thresholdResults.coTooHigh = false;
    
    // Act
    SystemState systemState = stateMachine.calculateState(validationResults, thresholdResults);

    // Assert
    TEST_ASSERT_TRUE(systemState == SystemState::Error);
}

void test_humidity_invalid_and_all_thresholds_ok_state_should_be_error()
{
    // Arrange
    ValidationResults validationResults;
    ThresholdResults thresholdResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = false;
    validationResults.coValid = true;

    thresholdResults.temperatureTooHigh = false;
    thresholdResults.temperatureTooLow = false;
    thresholdResults.humidityTooHigh = false;
    thresholdResults.humidityTooLow = false;
    thresholdResults.coTooHigh = false;
    
    // Act
    SystemState systemState = stateMachine.calculateState(validationResults, thresholdResults);

    // Assert
    TEST_ASSERT_TRUE(systemState == SystemState::Error);
}

void test_co_invalid_and_all_thresholds_ok_state_should_be_error()
{
    // Arrange
    ValidationResults validationResults;
    ThresholdResults thresholdResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = true;
    validationResults.coValid = false;

    thresholdResults.temperatureTooHigh = false;
    thresholdResults.temperatureTooLow = false;
    thresholdResults.humidityTooHigh = false;
    thresholdResults.humidityTooLow = false;
    thresholdResults.coTooHigh = false;
    
    // Act
    SystemState systemState = stateMachine.calculateState(validationResults, thresholdResults);

    // Assert
    TEST_ASSERT_TRUE(systemState == SystemState::Error);
}

void test_all_validations_valid_and_temperature_too_high_state_should_be_warning()
{
    // Arrange
    ValidationResults validationResults;
    ThresholdResults thresholdResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = true;
    validationResults.coValid = true;

    thresholdResults.temperatureTooHigh = true;
    thresholdResults.temperatureTooLow = false;
    thresholdResults.humidityTooHigh = false;
    thresholdResults.humidityTooLow = false;
    thresholdResults.coTooHigh = false;
    
    // Act
    SystemState systemState = stateMachine.calculateState(validationResults, thresholdResults);

    // Assert
    TEST_ASSERT_TRUE(systemState == SystemState::Warning);
}

void test_all_validations_valid_and_temperature_too_low_state_should_be_warning()
{
    // Arrange
    ValidationResults validationResults;
    ThresholdResults thresholdResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = true;
    validationResults.coValid = true;

    thresholdResults.temperatureTooHigh = false;
    thresholdResults.temperatureTooLow = true;
    thresholdResults.humidityTooHigh = false;
    thresholdResults.humidityTooLow = false;
    thresholdResults.coTooHigh = false;
    
    // Act
    SystemState systemState = stateMachine.calculateState(validationResults, thresholdResults);

    // Assert
    TEST_ASSERT_TRUE(systemState == SystemState::Warning);
}

void test_all_validations_valid_and_humidity_too_high_state_should_be_warning()
{
    // Arrange
    ValidationResults validationResults;
    ThresholdResults thresholdResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = true;
    validationResults.coValid = true;

    thresholdResults.temperatureTooHigh = false;
    thresholdResults.temperatureTooLow = false;
    thresholdResults.humidityTooHigh = true;
    thresholdResults.humidityTooLow = false;
    thresholdResults.coTooHigh = false;
    
    // Act
    SystemState systemState = stateMachine.calculateState(validationResults, thresholdResults);

    // Assert
    TEST_ASSERT_TRUE(systemState == SystemState::Warning);
}

void test_all_validations_valid_and_humidity_too_low_state_should_be_warning()
{
    // Arrange
    ValidationResults validationResults;
    ThresholdResults thresholdResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = true;
    validationResults.coValid = true;

    thresholdResults.temperatureTooHigh = false;
    thresholdResults.temperatureTooLow = false;
    thresholdResults.humidityTooHigh = false;
    thresholdResults.humidityTooLow = true;
    thresholdResults.coTooHigh = false;
    
    // Act
    SystemState systemState = stateMachine.calculateState(validationResults, thresholdResults);

    // Assert
    TEST_ASSERT_TRUE(systemState == SystemState::Warning);
}

void test_all_validations_valid_and_co_too_high_state_should_be_warning()
{
    // Arrange
    ValidationResults validationResults;
    ThresholdResults thresholdResults;
    StateMachine stateMachine;

    validationResults.temperatureValid = true;
    validationResults.humidityValid = true;
    validationResults.coValid = true;

    thresholdResults.temperatureTooHigh = false;
    thresholdResults.temperatureTooLow = false;
    thresholdResults.humidityTooHigh = false;
    thresholdResults.humidityTooLow = false;
    thresholdResults.coTooHigh = true;
    
    // Act
    SystemState systemState = stateMachine.calculateState(validationResults, thresholdResults);

    // Assert
    TEST_ASSERT_TRUE(systemState == SystemState::Warning);
}