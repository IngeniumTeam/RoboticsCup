#include <Arduino.h>

#include "Cherry.h"

Barrier::Barrier(uint8_t iPin, int iFrom = 0, int iTo = 90)
{
    from = iFrom;
    to = iTo;
    pin = iPin;
    pinMode(pin, OUTPUT);
}

void Barrier::setup()
{
    servo.attach(pin);
    move();
}

void Barrier::open()
{
    servo.write(to);
}

void Barrier::close()
{
    servo.write(from);
}

void Barrier::move()
{
    if (state)
        open();
    else
        close();
}

void Barrier::move(bool iState)
{
    if (state == iState)
        return;
    state = iState;
    move();
}

void Barrier::toggle()
{
    state = !state;
    move();
}