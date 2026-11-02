// TM1637 4-digit display (HW-069) - HH:MM clock, colon blinks every second
// Library: "TM1637" by Avishay Orpaz (install via Library Manager)

#include <TM1637Display.h>

#define CLK 2  // display CLK -> Arduino D2
#define DIO 3  // display DIO -> Arduino D3

// Set the starting time here, then upload
int hours = 20;
int minutes = 51;
int seconds = 0;

TM1637Display display(CLK, DIO);

unsigned long lastTick = 0;
bool colonOn = true;

void showTime() {
  int value = hours * 100 + minutes;
  // 0b01000000 = colon on, 0 = colon off; true = keep leading zeros
  display.showNumberDecEx(value, colonOn ? 0b01000000 : 0, true);
}

void setup() {
  display.setBrightness(5);  // 0 (dim) to 7 (bright)
  showTime();
  lastTick = millis();
}

void loop() {
  // Tick once per second (no delay(), so timing stays accurate)
  if (millis() - lastTick >= 1000) {
    lastTick += 1000;

    colonOn = !colonOn;  // colon blinks as the seconds indicator

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
