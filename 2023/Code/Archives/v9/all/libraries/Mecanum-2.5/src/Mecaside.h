#include <Arduino.h>

class Mecaside
{
public:
    Mecaside(int iSide)
    {
        side = iSide;
    }
    int side;
    void forward(int speed)
    {
        mecanum.motors[side][0].forward(speed);
        mecanum.motors[side][1].forward(speed);
    }
    void backward(int speed)
    {
        mecanum.motors[side][0].backward(speed);
        mecanum.motors[side][1].backward(speed);
    }
    void move(int speed)
    {
        if (speed > 0)
            forward(speed);
        if (speed == 0)
            stop();
        if (speed < 0)
            backward(-speed);
    }
    void stop()
    {
        mecanum.motors[side][0].stop();
        mecanum.motors[side][1].stop();
    }
};