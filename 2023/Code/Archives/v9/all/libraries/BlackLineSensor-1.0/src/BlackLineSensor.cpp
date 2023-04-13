#include <Arduino.h>

#include "BlackLineSensor.h"

/**
 * Setup the black line sensor
 */
BlackLineSensor::BlackLineSensor(uint8_t iPin1, uint8_t iPin2, uint8_t iPin3)
{
    pins[0] = iPin1;
    pins[1] = iPin2;
    pins[2] = iPin3;
}

/**
 * Get the raw value of readed the specified pin
 * 
 * @return bool the digital value of the specified pin
 */
bool BlackLineSensor::getRawValue(uint8_t pin)
{
    return digitalRead(pin);
}

/**
 * Get the value of the sensor after treatment
 * 
 * @return bool* an three length array containing values of the three sensors
 */
bool* BlackLineSensor::getValue()
{
    static bool value[3] = { getRawValue(pins[0]), getRawValue(pins[1]), getRawValue(pins[2]) };
    return value;
}

String BlackLineSensor::getPattern()
{
    bool* array = getValue();
    String pattern = String(array[0]) + String(array[1]) + String(array[2]);
    lastPattern = pattern;
    return pattern;
}
