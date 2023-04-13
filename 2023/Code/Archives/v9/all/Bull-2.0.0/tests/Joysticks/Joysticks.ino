void setup() {
  Serial.begin(9600);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}

void loop() {
  Serial.println(digitalRead(A5));
  Serial.println(analogRead(A4));
  Serial.println(analogRead(A3));
  Serial.println();
  Serial.println(digitalRead(A2));
  Serial.println(analogRead(A1));
  Serial.println(analogRead(A0));
  Serial.println();
  Serial.println();
  delay(100);
  // put your main code here, to run repeatedly:

}
