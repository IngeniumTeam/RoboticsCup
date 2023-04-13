#include <Bluetooth.h>
#include <Mecanum.h>
#include <Report.h>
#include <BlackLineSensor.h>
#include <Led.h>
#include <Cherry.h>
#include <Timeout.h>
#include <Digit.h>

#define loopTime 20
#define debugMode false
#define tankMode true

#define SERVO_1 13
#define SERVO_2 12
#define SERVO_3 11
#define SERVO_4 10
#define SERVO_5 9
#define SERVO_6 8
#define SERVO_7 7
#define SERVO_8 6

//                           left                              right                    mapping           //
//                 __________________________        __________________________       ____________        //
//                 top        bottom     stby        top        bottom    stby       from       to        //
//              _________    _________    __      _________    _________    _       _______   ______      //
Mecanum mecanum(34, 35, 4,   38, 39, 2,   25,     37, 36, 3,   32, 33, 5,   7,      0, 1023,  0, 150);    //
//             in1,in2,pwm  in1,in2,pwm          in1,in2,pwm, in1,in2,pwm           min,max   min,max     //

#include <Mecaside.h>
Mecaside left(Left);
Mecaside right(Right);

Bluetooth bluetooth(&Serial1);
Report report(&Serial, debugMode, 100);

BlackLineSensor blackLine(A0, A1, A2);

LedRGB bluetoothLed(28, 27, 26, true);
LedRGB led2(31, 30, 29, true);
Digit digit(49, 48, 7);

Barrier barrier(SERVO_1, 10, 120);
ToCake toCake(SERVO_2, SERVO_3, 90, 0, 50, 0);
ToBasket toBasket(SERVO_4);
Costume costume(SERVO_6, 0, 180);
Grabber grabber(SERVO_7, SERVO_8, 650, 2600, 400, 1000, 0, 130, 0, 130);

#include "AutoPilot.h"

int estimation = 70;

void setup ()
{
  // Serial setup //
  {
    Serial1.begin(9600);
    Serial.begin(9600);
#if debugMode
    Serial.println("Serial communication's on...");
    Serial.println("Bluetooth communication's on...");
    Serial.println("Debug mode's on...");
#endif
  }
  // Setup and stop the robot  //
  {
    barrier.setup();
    toCake.setup();
    toBasket.setup();
    costume.setup();
    costume.retract();
    grabber.setup();
    bluetoothLed.off();
    digit.display(estimation);
    stop();
    // autoPilot.drift(); // To drift // Only for fun // Do not use in tournament
  }
}

void loop ()
{
  report.print();
  if (bluetooth.receive())
  {
    if (bluetooth.lastError == DeserializationError::Ok)
    {
      report.ok++;
      report.prob = 0;
      bluetoothLed.on(0, 0, 255);
      {
#if debugMode
        Serial.print("estimation: "); Serial.println(bluetooth.json["estimation"].as<int>()); Serial.println();
#endif
        if (bluetooth.json["estimation"].as<int>() != -1 && bluetooth.json["estimation"].as<int>() != estimation) {
          estimation = bluetooth.json["estimation"].as<int>();
          Serial.println(estimation);
          digit.display(estimation);
        }
      }
      // Switch //
      {
#if debugMode
        Serial.print("switch: "); Serial.println(bluetooth.json["switch"].as<bool>()); Serial.println();
#endif
        barrier.move(bluetooth.json["switch"].as<bool>());
      }
      // Keypad //
      {
#if debugMode
        Serial.print("key: "); Serial.println(bluetooth.json["keypad"].as<int>()); Serial.println();
#endif
        switch (bluetooth.json["keypad"].as<int>())
        {
          case 1:
            //grabber.grab();
            break;
          case 2:
            toBasket.toggle();
            break;
          case 3:
            toCake.open();
            break;
          case 4:
            //autoPilot.line.find.left();
            break;
          case 5:
            //autoPilot.line.follow.forward();
            break;
          case 6:
            //autoPilot.line.find.right();
            break;
          case 10:
            costume.toggle();
            break;
          case 11:
            stop();
            break;
        }
      }
      // Motors //
      {
#if debugMode
        Serial.print("y.l: "); Serial.println(bluetooth.json["joysticks"]["left"]["y"].as<int>());
        Serial.print("y.r: "); Serial.println(bluetooth.json["joysticks"]["right"]["y"].as<int>()); Serial.println();
        Serial.print("x.l: "); Serial.println(bluetooth.json["joysticks"]["left"]["x"].as<int>());
        Serial.print("x.r: "); Serial.println(bluetooth.json["joysticks"]["right"]["x"].as<int>()); Serial.println(); Serial.println();
#endif
        // Y
        {
#if tankMode
          left.move(bluetooth.json["joysticks"]["left"]["y"].as<int>());
          right.move(bluetooth.json["joysticks"]["right"]["y"].as<int>());
#else
          left.move(bluetooth.json["joysticks"]["left"]["y"].as<int>());
          right.move(bluetooth.json["joysticks"]["left"]["y"].as<int>());
#endif
        }
        // X
        {
          mecanum.sideway(bluetooth.json["joysticks"]["left"]["x"].as<int>());
          mecanum.diagonal(bluetooth.json["joysticks"]["right"]["x"].as<int>(), bluetooth.json["joysticks"]["left"]["y"].as<int>());
        }
      }
      /*  // Response //
        {
        bluetooth.json.clear();
        bluetooth.json["blackLine"]["pattern"] = blackLine.getPattern();
        bluetooth.json["blackLine"]["onTheLine"] = blackLine.lastPattern == Position.Pattern.OnTheLine;
        bluetooth.send();
        }*/
    }
    else
    {
      report.inv++;
      report.prob++;
      bluetooth.empty();
      bluetoothLed.on(255, 0, 0);
    }
  }
  else
  {
    report.ntr++;
    report.prob++;
    bluetooth.empty();
    bluetoothLed.off();
  }
  if (report.prob >= 10)
  {
    stop();
  }
  delay(loopTime);
}

void stop ()
{
#if debugMode
  Serial.println("stop"); Serial.println();
#endif
  mecanum.stop();
}
/*void grabber_grab ()
{
    grabber_open();
    delay(1500);
    grabber_close();
    delay(750);
    grabber_up();
    delay(1500);
    grabber_open();
}

void grabber_open()
{
    servo2.write(to2);
    servo1.write(from1);
}

void grabber_close()
{
    servo2.write(from2);
}

void grabber_up()
{
    servo1.write(to1);
}*/
