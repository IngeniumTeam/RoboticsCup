#include <Arduino.h>

#include "Led.h"

Led::Led(uint8_t iPin, bool iReversed = false)
{
    pin = iPin;
    reversed = iReversed;
    pinMode(pin, OUTPUT);
    off();
}

void Led::apply()
{
    digitalWrite(pin, reversed ? !state : state);
}

/**
 * Turn on the led
 */
void Led::on()
{
    state = HIGH;
    apply();
}

/**
 * Turn off the led
 */
void Led::off()
{
    state = LOW;
    apply();
}

/**
 * Toggle the led state
 */
void Led::toggle()
{
    state = !state;
    apply();
}

/**
 * Make the led blinking
 * @param delay: the delay to wait between each tipping of the led
 * @param times: the number of times the led toggle
 */
void Led::blink(int delayTime, int times)
{
    for (int i = 0; i < times; i++)
    {
        toggle();
        delay(delayTime);
    }
}
