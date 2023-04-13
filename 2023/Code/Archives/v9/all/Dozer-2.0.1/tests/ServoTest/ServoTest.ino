#include <Servo.h>

Servo servo;

int testPin = 13;

void setup() {
  Serial.begin(9600);
  servo.attach(testPin);
}

void loop() {
  servo.write(0);
  Serial.println("0");
  delay(2000);
  servo.write(180);
  Serial.println("180");
  delay(2000);
}
