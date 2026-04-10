#pragma once
#include "IDisplayOutput.h"
#include <U8g2lib.h>

class OledDriver : public IDisplayOutput
{
    private:
        U8G2_SSD1306_128X64_NONAME_F_HW_I2C oled{U8G2_R0, U8X8_PIN_NONE};

    public:
        OledDriver() = default;
        void init();
        void clear() override;
        void writeLine(int line, const char* text) override;
        void display() override;
};