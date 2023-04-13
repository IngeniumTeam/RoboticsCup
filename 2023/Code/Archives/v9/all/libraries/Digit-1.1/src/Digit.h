#include <Arduino.h>
#include <TM1637Display.h>

class Digit
{
    public:
        Digit(uint8_t iPin1, uint8_t iPin2, int brightness = 5);
        void display(int number, bool leadingZero = false);
        uint8_t pin1;
        uint8_t pin2;
        TM1637Display digit = TM1637Display(0, 0);
};
