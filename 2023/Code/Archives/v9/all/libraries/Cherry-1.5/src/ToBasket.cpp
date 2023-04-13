#include <Arduino.h>

#include "Cherry.h"

ToBasket::ToBasket(uint8_t iPin, int iFrom = 0, int iTo = 90)
{
    from = iFrom;
    to = iTo;
    pin = iPin;
    pinMode(pin, OUTPUT);
}

void ToBasket::setup()
{
    servo.attach(pin);
    move();
}

void ToBasket::open()
{
    servo.write(to);
}

void ToBasket::close()
{
    servo.write(from);
}


void ToBasket::move()
{
    if (state)
        open();
    else
        close();
}

void ToBasket::move(bool iState)
{
    state = iState;
    move();
}

void ToBasket::toggle ()
{
    state = !state;
    move();
}