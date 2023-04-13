#include <Arduino.h>

#include "Joystick.h"

/**
 * Setup the joystick
 */
Joystick::Joystick(uint8_t xPin, uint8_t yPin, uint8_t cPin, bool xReversed, bool yReversed, int xRest, int yRest, int xMargin, int yMargin)
{
    x = Potentiometer(xPin, xReversed, xRest, xMargin);
    y = Potentiometer(yPin, yReversed, yRest, yMargin);
    clck = Button(cPin);
}

Joystick::Joystick(uint8_t xPin, uint8_t yPin, uint8_t cPin)
{
    x = Potentiometer(xPin);
    y = Potentiometer(yPin);
    clck = Button(cPin);
}