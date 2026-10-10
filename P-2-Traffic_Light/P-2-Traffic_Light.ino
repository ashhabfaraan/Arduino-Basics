void setup()
{
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  digitalWrite(5, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
  delay(5000); 
  digitalWrite(5, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(9, LOW);
  delay(1000);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  digitalWrite(9, HIGH);
  delay(5000);
}
