//#include <BlackLineSensor.h>

//BlackLineSensor blck(A2, A3, A4);

void setup() {
  Serial.begin(9600);
pinMode(A2, INPUT);
pinMode(A3, INPUT);
pinMode(A4, INPUT);
}

void loop() {
  //bool* values = blck.getValue();
  bool values[3] = { digitalRead(A2), digitalRead(A3), digitalRead(A4) };
  Serial.println(values[0]);
  Serial.println(values[1]);
  Serial.println(values[2]);
  Serial.println();
  delay(500);
}
