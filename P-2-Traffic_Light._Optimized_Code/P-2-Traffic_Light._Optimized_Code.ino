// USING VARIABLES IN THE CODE
// THIS WILL HELP TO CHANGE THINGS ONCE SO WE DO NOT HAVE TO CHANGE THINGS EVERYWHERE
int DELAY_TIME_GREEN_AND_RED = 3000;
int DELAY_TIME_YELLOW = 1000;
int GREEN = 5;
int YELLOW = 7;
int RED = 9;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  // Green
  digitalWrite(GREEN, HIGH);
  delay(DELAY_TIME_GREEN_AND_RED);
  digitalWrite(GREEN, LOW);
  // Yellow
  digitalWrite(YELLOW, HIGH);
  delay( DELAY_TIME_YELLOW);
  digitalWrite(YELLOW, LOW);
  // Red
  digitalWrite(RED, HIGH);
  delay(DELAY_TIME_GREEN_AND_RED);
  digitalWrite(RED, LOW);
}