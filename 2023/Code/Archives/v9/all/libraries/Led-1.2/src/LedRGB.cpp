#include <Arduino.h>

#include "Led.h"

LedRGB::LedRGB(uint8_t rPin, uint8_t gPin, uint8_t bPin, bool iAnode = false)
{
    pins[0] = rPin;
    pins[1] = gPin;
    pins[2] = bPin;
    anode = iAnode;
    pinMode(pins[0], OUTPUT);
    pinMode(pins[1], OUTPUT);
    pinMode(pins[2], OUTPUT);
    off();
}

void LedRGB::apply()
{
    digitalWrite(pins[0], state ? (!anode ? r : !r) : 0);
    digitalWrite(pins[1], state ? (!anode ? g : !g) : 0);
    digitalWrite(pins[1], state ? (!anode ? b : !b) : 0);
}

/**
 * Turn on the led
 */
void LedRGB::on(bool iR, bool iG, bool iB)
{
    r = iR;
    g = iG;
    b = iB;
    on();
}

/**
 * Turn on the led
 */
void LedRGB::on()
{
    state = true;
    apply();
}

/**
 * Turn off the led
 */
void LedRGB::off()
{
    state = false;
    apply();
}

/**
 * Toggle the led state
 */
void LedRGB::toggle()
{
    state = !state;
    apply();
}

/**
 * Make the led blinking
 * @param delay: the delay to wait between each tipping of the led
 * @param times: the number of times the led toggle
 */
void LedRGB::blink(int delayTime, int times)
{
    for (int i = 0; i < times; i++)
    {
        toggle();
        delay(delayTime);
    }
}
