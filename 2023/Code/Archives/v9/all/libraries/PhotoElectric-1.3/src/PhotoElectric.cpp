#include <Arduino.h>

#include "PhotoElectric.h"

PhotoElectric::PhotoElectric(uint8_t iPin, int iMinCount = 1)
{
    pin = iPin;
    minCount = iMinCount;
    pinMode(pin, INPUT);
}

/**
 * Get the value of the photo electric's pin
 *
 * @return bool true if an object obstructs the sensor, false otherwise
 */
bool PhotoElectric::detects()
{
    if (!state())
    {
        // while (!state());
        count++;
        if (count >= minCount)
        {
            count = 0;
            return true;
        }
    }
    return false;
}

bool PhotoElectric::state()
{
    return digitalRead(pin);
}
