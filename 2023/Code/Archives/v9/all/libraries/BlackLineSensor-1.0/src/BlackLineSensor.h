#include <Arduino.h>

struct
{
    struct
    {
        const String OnTheLine = "101";
        const String OnTheRight = "110";
        const String OnTheLeft = "011";
    } Pattern;
    const bool OnTheLine[3] = { true, false, true };
    const bool OnTheRight[3] = { true, true, false };
    const bool OnTheLeft[3] = { false, true, true };
} Position;

class BlackLineSensor
{
    public:
        BlackLineSensor(uint8_t iPin1, uint8_t iPin2, uint8_t iPin3);
        bool getRawValue(uint8_t pin);
        bool* getValue();
        String getPattern();
        uint8_t pins[3];
        String lastPattern;
};
