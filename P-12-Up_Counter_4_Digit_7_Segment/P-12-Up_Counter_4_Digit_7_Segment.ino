// TM1637 4-digit display (HW-069) demo
// Library: "TM1637" by Avishay Orpaz (install via Library Manager)

#include <TM1637Display.h>

#define CLK 2   // display CLK -> Arduino D2
#define DIO 3   // display DIO -> Arduino D3

TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(5);        // 0 (dim) to 7 (bright)
  display.clear();

  // Test: light every segment for 1 second
  uint8_t all[] = {0xFF, 0xFF, 0xFF, 0xFF};
  display.setSegments(all);
  delay(1000);
}

void loop() {
  // MM:SS style counter, counts 00:00 to 99:59
  for (int m = 0; m < 100; m++) {
    for (int s = 0; s < 60; s++) {
      int value = m * 100 + s;
      // 0b01000000 turns the colon on, true = show leading zeros
      display.showNumberDecEx(value, 0b01000000, true);
      delay(1000);
    }
  }
}