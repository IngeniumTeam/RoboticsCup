#include <Arduino.h>

#include "Led.h"

LedRGBAnalog::LedRGBAnalog(uint8_t rPin, uint8_t gPin, uint8_t bPin, bool iAnode = false)
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

void LedRGBAnalog::apply()
{
    analogWrite(pins[0], state ? (!anode ? r : 255 - r) : 0);
    analogWrite(pins[1], state ? (!anode ? g : 255 - g) : 0);
    analogWrite(pins[1], state ? (!anode ? b : 255 - b) : 0);
}

/**
 * Turn on the led
 */
void LedRGBAnalog::on(int iR, int iG, int iB)
{
    state = true;
    r = iR;
    g = iG;
    b = iB;
    apply();
}

/**
 * Turn on the led
 */
void LedRGBAnalog::on()
{
    state = true;
    apply();
}

/**
 * Turn off the led
 */
void LedRGBAnalog::off()
{
    state = false;
    apply();
}

/**
 * Toggle the led state
 */
void LedRGBAnalog::toggle()
{
    state = !state;
    apply();
}

/**
 * Make the led blinking
 * @param delay: the delay to wait between each tipping of the led
 * @param times: the number of times the led toggle
 */
void LedRGBAnalog::blink(int delayTime, int times)
{
    for (int i = 0; i < times; i++)
    {
        toggle();
        delay(delayTime);
    }
}
