void setup() {
  Serial.begin(9600);
  int length = 6;
  int points[length] = { 0, 130, 180, 200, 230, 255 };
  for (int x = 0; x < 1024; x += 10)
  {
    Serial.println(mapPoints(x, 0, 1023, points, length));
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

int mapPoints (int value, int min, int max, int* points, int length)
{
  int newValue = 0;
  if (length <= 1) return -1;
  for (int i = 0; i < (length - 1); i++)
  {
    if (!(points[i] < points[i + 1]))
      return -1;
    int tempValue = map(value, min, max, points[0], points[length - 1]);
    if (tempValue >= points[i] && tempValue <= points[i + 1])
      newValue = map(value, min, max, points[i], points[i + 1]);
  }
  return newValue;
}
