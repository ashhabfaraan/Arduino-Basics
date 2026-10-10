int passiveBuzz = 9;

void setup()
{
  pinMode(passiveBuzz, OUTPUT);
}

void loop()
{
  analogWrite(passiveBuzz, 50);
  delay(10);
  analogWrite(passiveBuzz, 0);
  delay(10);
}
