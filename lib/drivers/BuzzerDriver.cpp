#include <BuzzerDriver.h>
#include <HardwareConfig.h>
#include <gpio.h>

void BuzzerDriver::init()
{
    gpio_init(HardwareConfig::BUZZER_DIGITAL_PIN, GPIO_DIRECTION_OUTPUT);
}

void BuzzerDriver::activate()
{
    gpio_write(HardwareConfig::BUZZER_DIGITAL_PIN, GPIO_LEVEL_HIGH);
}

void BuzzerDriver::deactivate()
{
    gpio_write(HardwareConfig::BUZZER_DIGITAL_PIN, GPIO_LEVEL_LOW);
}