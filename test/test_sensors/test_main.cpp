#include <unity.h>
#include <SensorValidator.h>

SensorValidator sensorValidator;
Measurements measurements;
ValidationResults validationResults;

// Wird vor JEDEM Test aufgerufen
void setUp()
{
    measurements.temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
    measurements.humidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;
    measurements.co = SensorConstants::CO_NOT_INITIALIZED;

    validationResults.temperatureValid = false;
    validationResults.humidityValid = false;
    validationResults.coValid = false;
}

// Wird nach JEDEM Test aufgerufen
void tearDown() {
    
    // Hier könntest du aufräumen
}

void test_temperature_not_initialized_should_be_invalid()
{
    measurements.temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
    validationResults = sensorValidator.validateAllSensors(measurements);
    TEST_ASSERT_FALSE(validationResults.temperatureValid);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_temperature_not_initialized_should_be_invalid);
    return UNITY_END();
}