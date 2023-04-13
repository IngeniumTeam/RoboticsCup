#include <Arduino.h>

#include "Cherry.h"

Grabber::Grabber(uint8_t iPin1, uint8_t iPin2, int iPulseMin1, int iPulseMax1, int iPulseMin2, int iPulseMax2, int iFrom1 = 0, int iTo1 = 180, int iFrom2 = 130, int iTo2 = 160)
{
    pulseMin1 = iPulseMin1;
    pulseMax1 = iPulseMax1;
    pulseMin2 = iPulseMin2;
    pulseMax2 = iPulseMax2;
    from1 = iFrom1;
    to1 = iTo1;
    from2 = iFrom2;
    to2 = iTo2;
    pin1 = iPin1;
    pin2 = iPin2;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

void Grabber::setup()
{
    servo1.attach(pin1, pulseMin1, pulseMax1);
    servo2.attach(pin2, pulseMin2, pulseMax2);
    open();
}

void Grabber::grab()
{
    open();
    delay(1500);
    close();
    delay(750);
    up();
    delay(1500);
    open();
}

void Grabber::open()
{
    servo2.write(to2);
    servo1.write(from1);
}

void Grabber::close()
{
    servo2.write(from2);
}

void Grabber::up()
{
    servo1.write(to1);
}