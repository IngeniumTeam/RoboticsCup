#include <Arduino.h>

#include "Motor.h"

/**
 * Setup the Motor
 */
Motor::Motor(uint8_t iIn1, uint8_t iIn2, uint8_t iPwm, uint8_t iStandBy, int iFromMin = 0, int iFromMax = 255, int iToMin = 0, int iToMax = 255)
{
	fromMin = iFromMin;
	fromMax = iFromMax;
	toMin = iToMin;
	toMax = iToMax;
	in1 = iIn1;
	in2 = iIn2;
	pwm = iPwm;
	standby = iStandBy;
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(pwm, OUTPUT);
	pinMode(standby, OUTPUT);
	digitalWrite(standby, HIGH);
}

void Motor::move(int speed)
{
	if (speed > 0)
	{
		forward(speed);
	}
	if (speed < 0)
	{
		backward(-speed);
	}
}

void Motor::forward(int speed)
{
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	analogWrite(pwm, map(speed, fromMin, fromMax, toMin, toMax));
}

void Motor::backward(int speed)
{
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	analogWrite(pwm, map(speed, fromMin, fromMax, toMin, toMax));
}

void Motor::stop()
{
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	analogWrite(pwm, 0);
}

void Motor::brake()
{
	digitalWrite(in1, HIGH);
	digitalWrite(in2, HIGH);
	analogWrite(pwm, 0);
}