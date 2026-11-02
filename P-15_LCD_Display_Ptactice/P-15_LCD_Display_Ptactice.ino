#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const byte COLS = 16;
const byte ROWS = 2;

LiquidCrystal_I2C *lcd;
char screen[ROWS][COLS + 1];   // copy of what's on the LCD
byte curCol = 0, curRow = 0;   // logical cursor position

byte findI2CAddress() {
  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) return addr;
  }
  return 0;
}

// ---------- screen helpers ----------
void refresh() {
  for (byte r = 0; r < ROWS; r++) {
    lcd->setCursor(0, r);
    lcd->print(screen[r]);
  }
  lcd->setCursor(curCol, curRow);   // puts the visible cursor in place
}

void clearLine(byte r) {
  memset(screen[r], ' ', COLS);
  screen[r][COLS] = '\0';
}

void clearAll() {
  clearLine(0);
  clearLine(1);
  curCol = 0;
  curRow = 0;
}

void writeChar(char c) {
  if (curCol >= COLS) {             // line full -> go to next line if any
    if (curRow + 1 >= ROWS) return;
    curRow++;
    curCol = 0;
  }
  screen[curRow][curCol++] = c;
}

void deleteChars(int n) {
  while (n-- > 0) {
    if (curCol == 0) {
      if (curRow == 0) return;
      curRow--;
      curCol = COLS;
    }
    curCol--;
    screen[curRow][curCol] = ' ';
  }
}

void setLine(byte r, const String &text) {
  clearLine(r);
  byte n = min((int)text.length(), (int)COLS);
  for (byte i = 0; i < n; i++) screen[r][i] = text[i];
  curRow = r;
  curCol = n;
}

// ---------- help ----------
void printHelp() {
  Serial.println(F("--- LCD commands ---"));
  Serial.println(F("print <text>      write text at cursor (alias: p)"));
  Serial.println(F("l1 <text>         replace line 1"));
  Serial.println(F("l2 <text>         replace line 2"));
  Serial.println(F("del [n]           delete last n chars (default 1)"));
  Serial.println(F("clearline <1|2>   clear one line"));
  Serial.println(F("clear             clear whole screen"));
  Serial.println(F("goto <col> <row>  move cursor (col 1-16, row 1-2)"));
  Serial.println(F("cursor on|off     show underline cursor"));
  Serial.println(F("blink on|off      blinking block cursor"));
  Serial.println(F("bl on|off         backlight"));
  Serial.println(F("scroll left|right shift display"));
  Serial.println(F("home              reset scroll/cursor"));
  Serial.println(F("help              show this list"));
}

// ---------- command handler ----------
void handleCommand(String line) {
  line.trim();
  if (line.length() == 0) return;

  int sp = line.indexOf(' ');
  String cmd = (sp < 0) ? line : line.substring(0, sp);
  String arg = (sp < 0) ? ""   : line.substring(sp + 1);
  cmd.toLowerCase();

  if (cmd == "print" || cmd == "p") {
    for (unsigned int i = 0; i < arg.length(); i++) writeChar(arg[i]);
    refresh();
  }
  else if (cmd == "l1") { setLine(0, arg); refresh(); }
  else if (cmd == "l2") { setLine(1, arg); refresh(); }
  else if (cmd == "del") {
    int n = arg.length() ? arg.toInt() : 1;
    deleteChars(n);
    refresh();
  }
  else if (cmd == "clearline") {
    int r = arg.toInt();
    if (r == 1 || r == 2) {
      clearLine(r - 1);
      curRow = r - 1;
      curCol = 0;
      refresh();
    } else Serial.println(F("Use: clearline 1  or  clearline 2"));
  }
  else if (cmd == "clear") { clearAll(); refresh(); }
  else if (cmd == "goto") {
    int sp2 = arg.indexOf(' ');
    int c = arg.toInt();
    int r = (sp2 < 0) ? 1 : arg.substring(sp2 + 1).toInt();
    if (c >= 1 && c <= COLS && r >= 1 && r <= ROWS) {
      curCol = c - 1;
      curRow = r - 1;
      lcd->setCursor(curCol, curRow);
    } else Serial.println(F("Use: goto <col 1-16> <row 1-2>"));
  }
  else if (cmd == "cursor") { arg == "on" ? lcd->cursor() : lcd->noCursor(); }
  else if (cmd == "blink")  { arg == "on" ? lcd->blink()  : lcd->noBlink(); }
  else if (cmd == "bl")     { arg == "on" ? lcd->backlight() : lcd->noBacklight(); }
  else if (cmd == "scroll") {
    if (arg == "left")  lcd->scrollDisplayLeft();
    else if (arg == "right") lcd->scrollDisplayRight();
    else Serial.println(F("Use: scroll left  or  scroll right"));
  }
  else if (cmd == "home") {
    lcd->home();
    curCol = 0;
    curRow = 0;
    refresh();
  }
  else if (cmd == "help") printHelp();
  else Serial.println(F("Unknown command. Type: help"));
}

// ---------- main ----------
void setup() {
  Serial.begin(9600);
  Wire.begin();

  byte addr = findI2CAddress();
  if (addr == 0) {
    Serial.println(F("No I2C device found. Check wiring."));
    addr = 0x27;
  }

  lcd = new LiquidCrystal_I2C(addr, COLS, ROWS);
  lcd->init();
  lcd->backlight();

  clearAll();
  setLine(0, "Ready! Type help");
  setLine(1, "in Serial Monitor");
  refresh();

  Serial.println(F("LCD ready. Set Serial Monitor to 'Newline'."));
  printHelp();
}

void loop() {
  if (Serial.available()) {
    handleCommand(Serial.readStringUntil('\n'));
  }
}