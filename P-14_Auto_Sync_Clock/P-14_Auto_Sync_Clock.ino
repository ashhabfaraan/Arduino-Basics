// TM1637 HH:MM clock for Arduino Uno - time is synced from the laptop over USB
// Run sync_time.py on the laptop while the Uno is plugged in.
// If no laptop sync arrives, it starts from the time the sketch was compiled.
// Library: "TM1637" by Avishay Orpaz (install via Library Manager)

#include <TM1637Display.h>

#define CLK 2   // display CLK -> Arduino D2
#define DIO 3   // display DIO -> Arduino D3

TM1637Display display(CLK, DIO);

int hours = 0, minutes = 0, seconds = 0;
unsigned long lastTick = 0;
bool colonOn = true;

void showTime() {
  int value = hours * 100 + minutes;
  display.showNumberDecEx(value, colonOn ? 0b01000000 : 0, true);
}

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);
  display.setBrightness(5);   // 0 (dim) to 7 (bright)

  // Fallback start time = compile time (format "HH:MM:SS")
  sscanf(__TIME__, "%d:%d:%d", &hours, &minutes, &seconds);

  showTime();
  lastTick = millis();
}

void checkSerialSync() {
  if (Serial.available()) {
    String line = Serial.readStringUntil('\n');   // expected: T20:51:30
    int h, m, s;
    if (sscanf(line.c_str(), "T%d:%d:%d", &h, &m, &s) == 3) {
      hours = h;
      minutes = m;
      seconds = s;
      colonOn = true;
      lastTick = millis();
      showTime();
    }
  }
}

void loop() {
  checkSerialSync();

  if (millis() - lastTick >= 1000) {
    lastTick += 1000;
    colonOn = !colonOn;   // colon blinks as the seconds indicator

    seconds++;
    if (seconds >= 60) {
      seconds = 0;
      minutes++;
      if (minutes >= 60) {
        minutes = 0;
        hours++;
        if (hours >= 24) hours = 0;
      }
    }
    showTime();
  }
}