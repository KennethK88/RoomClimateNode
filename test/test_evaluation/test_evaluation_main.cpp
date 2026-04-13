#include <unity.h>

// Wird vor JEDEM Test aufgerufen
void setUp()
{

}

// Wird nach JEDEM Test aufgerufen
void tearDown() {
    
    // Hier könntest du aufräumen
}

void test_temperature_not_initialized_should_be_invalid();
void test_humidity_not_initialized_should_be_invalid();
void test_co_not_initialized_should_be_invalid();

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_temperature_not_initialized_should_be_invalid);
    RUN_TEST(test_humidity_not_initialized_should_be_invalid);
    RUN_TEST(test_co_not_initialized_should_be_invalid);
    return UNITY_END();
}