#include <Arduino.h>

#include "Cherry.h"

Costume::Costume(uint8_t iPin, int iFrom = 0, int iTo = 180)
{
    from = iFrom;
    to = iTo;
    pin = iPin;
    pinMode(pin, OUTPUT);
}

void Costume::setup()
{
    servo.attach(pin);
}

void Costume::deploy()
{
    servo.write(to);
}

void Costume::retract()
{
    servo.write(from);
}

void Costume::toggle()
{
    if (state)
        deploy();
    else
        retract();
    state = !state;

}