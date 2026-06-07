#include <LedDriver.h>

void LedDriver::init()
{
    gpio_init(gpioPin, GPIO_DIRECTION_OUTPUT);
}

void LedDriver::turnOn()
{
    gpio_write(gpioPin, GPIO_LEVEL_HIGH);
}

void LedDriver::turnOff()
{
    gpio_write(gpioPin, GPIO_LEVEL_LOW);
}