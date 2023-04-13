#include <Keypad.h>

int fromPin = 4;
char keys[4][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };
byte rowPins[4] = { 5, 10, 9, 7 };
byte colPins[3] = { 6, 4, 8 };
byte rows = 4;
byte cols = 3;
Keypad keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("key: ");
  int value = keypad.getKey();
  Serial.println(value);
  delay(100);
}
