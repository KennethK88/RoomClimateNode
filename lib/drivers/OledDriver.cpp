#include "display/OledDriver.h"

static u8g2_uint_t lineToY(int line)
{
    u8g2_uint_t yStart = 12;
    u8g2_uint_t ySpacing = 16;
    return (yStart + line * ySpacing);
}

void OledDriver::init()
{
    oled.begin();
    oled.setFont(u8g2_font_ncenB08_tr);
}

void OledDriver::clear()
{
    oled.clearBuffer();
}

void OledDriver::writeLine(int line, const char* text)
{
    oled.drawStr(0, lineToY(line), text);
}

void OledDriver::display()
{
    oled.sendBuffer();
}

void OledDriver::sleepOn()
{
    oled.sleepOn();
}

void OledDriver::sleepOff()
{
    oled.sleepOff();
}