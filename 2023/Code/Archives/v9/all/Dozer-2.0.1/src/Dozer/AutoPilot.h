class AutoPilot
{
  public:
    AutoPilot() {}
    struct Line
    {
      struct Follow
      {
        void forward (int speed = 1023)
        {
          while (true)
          {
            mecanum.forward(speed);
            while (blackLine.getPattern() == Position.Pattern.OnTheRight)
              left.stop();
            mecanum.forward(speed);
            while (blackLine.getPattern() == Position.Pattern.OnTheLeft)
              right.stop();
          }
        }
        void backward (int speed = 1023)
        {
          while (true)
          {
            mecanum.backward(speed);
            while (blackLine.getPattern() == Position.Pattern.OnTheRight)
              right.stop();
            mecanum.backward(speed);
            while (blackLine.getPattern() == Position.Pattern.OnTheLeft)
              left.stop();
          }
        }
      } follow;
      struct Find
      {
        void left (int speed = 512)
        {
          mecanum.sidewayLeft(speed);
          while (blackLine.getPattern() != Position.Pattern.OnTheLine);
          mecanum.stop();
        }
        void right (int speed = 512)
        {
          mecanum.sidewayRight(speed);
          while (blackLine.getPattern() != Position.Pattern.OnTheLine);
          mecanum.stop();
        }
      } find;
    } line;
    void goBackToCherry ()
    {
      mecanum.backward(512);
      while (blackLine.getPattern() == Position.Pattern.OnTheLine);
      if (blackLine.getPattern() != Position.Pattern.OnTheLine)
      {
        if (blackLine.getPattern() == Position.Pattern.OnTheRight)
        {
          left.backward(512);
          right.forward(512);
          while (blackLine.getPattern() != Position.Pattern.OnTheLine);
          mecanum.stop();
          goBackToCherry();
        }
      }
      else
      {
        mecanum.stop();
      }
    }
    void drift ()
    {
      mecanum.forward(1023);
      delay(700);
      left.forward(128);
      delay(300);
      mecanum.sidewayRight(1023);
      delay(500);
      right.forward(1023);
      left.forward(128);
      delay(100);
      left.forward(1023);
      right.forward(128);
      delay(100);
      mecanum.forward(1023);
      delay(500);
      mecanum.stop();
    }
    void winDance ()
    {
      left.forward(1023);
      right.backward(1023);
      delay(1000);
      right.forward(1023);
      left.backward(1023);
      delay(1000);
      mecanum.forward(1023);
      delay(100);
      mecanum.backward(1023);
      delay(200);
      mecanum.forward(1023);
      delay(100);
      right.forward(1023);
      left.backward(1023);
      delay(1000);
    }
} autoPilot;
