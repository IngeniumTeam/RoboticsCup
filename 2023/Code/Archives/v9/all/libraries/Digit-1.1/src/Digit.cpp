#include <Arduino.h>

#include "Digit.h"

Digit::Digit(uint8_t iPin1, uint8_t iPin2, int brightness = 5)
{
    pin1 = iPin1;
    pin2 = iPin2;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    digit = TM1637Display(pin1, pin2);
    digit.setBrightness(brightness);
}

/**
 * Display a number on the digit display
 */
void Digit::display(int number, bool leadingZero = false)
{
    digit.showNumberDec(number, leadingZero);
}
