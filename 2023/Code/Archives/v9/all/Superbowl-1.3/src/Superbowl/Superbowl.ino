#include <Digit.h>
#include <PhotoElectric.h>

Digit digit(4, 3);
PhotoElectric photoElectric(5, 3);

int cherryNumber = 0;

void setup () {
  digit.display(cherryNumber);
}

void loop () {
  if (photoElectric.detects()) {
    cherryNumber++;
    digit.display(cherryNumber);
  }
}
