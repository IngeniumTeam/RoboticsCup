#include <Bluetooth.h>
#include <Report.h>

#define loopTime 40

Bluetooth bluetooth(&Serial1);
Report report(&Serial, true, 100);

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  Serial.println("Serial communication's on...");
  Serial.println("Bluetooth communication's on...");
}

void loop() {
  report.print();
  if (bluetooth.receive())
  {
    if (bluetooth.lastError == DeserializationError::Ok)
    {
      report.ok++;
      report.prob = 0;
      serializeJsonPretty(bluetooth.json, Serial);
    }
    else
    {
      report.inv++;
      report.prob++;
      bluetooth.empty();
    }
  }
  else
  {
    report.ntr++;
    report.prob++;
    bluetooth.empty();
  }
  if (report.prob >= 10)
  {
    Serial.println("stop");
  }
  delay(loopTime);
}
