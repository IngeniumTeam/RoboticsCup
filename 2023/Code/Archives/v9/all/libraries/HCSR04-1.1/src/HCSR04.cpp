#include <Arduino.h>

#include "HCSR04.h"

/**
 * Setup the HCSR04
 */
HCSR04::HCSR04(uint8_t iTriggerPin, uint8_t iEchoPin, int iLowLimit = 1, int iHighLimit = 100)
{
    triggerPin = iTriggerPin;
    echoPin = iEchoPin;
    lowLimit = iLowLimit;
    highLimit = iHighLimit;
}

/**
 * Get the raw value of readed the HCSR04
 * 
 * @return int the distance in centimeters readed on the HCSR04
 */
int HCSR04::getRawValue()
{
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    return pulseIn(echoPin, HIGH) * 0.034 / 2;
}

/**
 * Get the value of the HCSR04 after treatment
 * 
 * @return int -1 if the `rawValue` is less than the `lowLimit`, -2 if more than the `highLimit` and the `rawValue` otherwise
 */
int HCSR04::getValue()
{
    int value;
    int rawValue = getRawValue();
    if (rawValue < lowLimit)
        value = -1;
    if (rawValue > highLimit)
        value = -2;
    return value;
}
