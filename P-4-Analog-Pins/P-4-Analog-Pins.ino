// How do we know the difference between digital and analog pins?
// For Analog Pins we Place A in front of the number.

int readPin = A5;
float calcVal = 0;
void setup()
{
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  calcVal = (5.0/1023) * (analogRead(readPin));
  Serial.println(calcVal);
  delay(500);
}