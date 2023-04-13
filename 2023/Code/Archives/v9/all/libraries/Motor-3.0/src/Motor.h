#include <Arduino.h>

class Motor
{
    public:
        Motor(uint8_t iIn1, uint8_t iIn2, uint8_t iPwm, uint8_t iStandBy, int iFromMin = 0, int iFromMax = 255, int iToMin = 0, int iToMax = 255);
        void move(int speed);
        void forward(int speed);
        void backward(int speed);
        void stop();
        void brake();
        int in1;
        int in2;
        int pwm;
        int standby;
        int fromMin = 0;
        int fromMax = 255;
        int toMin = 0;
        int toMax = 255;
};
