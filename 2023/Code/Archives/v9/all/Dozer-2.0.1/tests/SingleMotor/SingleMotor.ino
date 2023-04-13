#include <Motor.h>

Motor m1 (34, 35, 4, 25);

void setup() {
  m1.forward(255);
  delay(1000);
  m1.backward(255);
  delay(1000);
  m1.move(255);
  delay(1000);
  m1.move(-255);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

}
