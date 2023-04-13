void setup() {
  Serial.begin(9600);
}

void loop() {
  int r = 1023;
  int l = 1023;
  Serial.print("{\"joysticks\":{\"left\":{\"x\":512,\"y\":"); Serial.print(l); Serial.print(",\"clck\":true},\"right\":{\"x\":512,\"y\":"); Serial.print(r); Serial.println(",\"clck\":false}}}");
  delay(200);
}
