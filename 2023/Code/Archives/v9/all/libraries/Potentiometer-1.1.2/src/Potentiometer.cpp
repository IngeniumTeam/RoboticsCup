#include <Arduino.h>

#include "Potentiometer.h"

/**
 * Setup the potentiometer
 */
Potentiometer::Potentiometer(uint8_t iPin, bool iReversed = false, int iRest = 512, int iMargin = 50)
{
    pin = iPin;
    reversed = iReversed;
    rest = iRest;
    margin = iMargin;
    pinMode(pin, INPUT);
}

/**
 * Get the raw value of readed on the potentiometer's pin
 * 
 * @return int the analog value of `Potentiometer::pin`
 */
int Potentiometer::getRawValue()
{
    return analogRead(pin);
}

/**
 * Get the value of the potentiometer after treatment
 * 
 * @return int -1 if the potentiometer is in rest position (the raw value is between `rest - margin` and `rest + margin`) ; -3 if the potentiometer is in a fullback position (the raw value is less than `0 + margin`) ; -2 if the potentiometer is in a fullforward position (the raw value is more than `1023 - margin`) ; the raw value of the potentiometer else
 */
int Potentiometer::getValue()
{
    int rawValue = getRawValue();
    int finalValue = (rawValue - rest) * 2;
    if (reversed)
        finalValue *= -1;
    if (finalValue >= 1023 - margin) finalValue = 1023;
    if (finalValue <= -1023 + margin) finalValue = -1023;
    if (finalValue <= 0 + margin && finalValue >= 0 - margin) finalValue = 0;
    lastValue = finalValue;
    return finalValue;
}
