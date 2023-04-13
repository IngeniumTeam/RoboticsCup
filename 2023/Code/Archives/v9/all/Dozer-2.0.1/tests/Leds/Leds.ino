#include <Led.h>

LedRGB led1(26, 27, 28, true);
LedRGB led2(29, 30, 31, true);

void setup() {
  led1.on(0, 0, 255);
  led2.off();
}

void loop() {
  // put your main code here, to run repeatedly:

}
