#pragma once

class IDisplayOutput
{
    public:
        virtual ~IDisplayOutput() = default;
        virtual void clear() = 0;
        virtual void writeLine(int line, const char* text) = 0;
        virtual void display() = 0;
};