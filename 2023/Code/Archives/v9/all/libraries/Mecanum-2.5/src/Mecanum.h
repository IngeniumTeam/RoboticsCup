#include <Arduino.h>
#include <Motor.h>

#define Left 0
#define Right 1
#define Front 0
#define Back 1

class Mecanum
{
public:
	Mecanum(uint8_t in1_1, uint8_t in1_2, uint8_t pwm1,
			uint8_t in2_1, uint8_t in2_2, uint8_t pwm2, uint8_t standBy1,
			uint8_t in3_1, uint8_t in3_2, uint8_t pwm3,
			uint8_t in4_1, uint8_t in4_2, uint8_t pwm4, uint8_t standBy2,
			int fromMin = 0, int fromMax = 1023, int toMin = 0, int toMax = 255);
	void forward(int speed);
	void backward(int speed);
	void move(int speed);
	void stop();
	void sideway(int speed);
	void sidewayLeft(int speed);
	void sidewayRight(int speed);
	void diagonal(int xSpeed, int ySpeed);
	void diagonalLeft(int speed);
	void diagonalLeftForward(int speed);
	void diagonalLeftBackward(int speed);
	void diagonalRight(int speed);
	void diagonalRightForward(int speed);
	void diagonalRightBackward(int speed);
	Motor motors[2][2] = {{Motor(0, 0, 0, 0), Motor(0, 0, 0, 0)}, {Motor(0, 0, 0, 0), Motor(0, 0, 0, 0)}};
};