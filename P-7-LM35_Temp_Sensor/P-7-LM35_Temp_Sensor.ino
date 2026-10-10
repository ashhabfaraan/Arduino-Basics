int readPin = A2;
float scale_f = 0.01;
float Temp;
float readValue;
float calcValue;
float Temp_F;
float Temp_K;
void setup() {
  // put your setup code here, to run once:
  pinMode(readPin, INPUT);  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readValue = analogRead(readPin);
  calcValue = readValue * (5.0/1023.0);
  Temp = calcValue / scale_f;
  Temp_F = ((Temp) * (9 / 5)) + 32;
  Temp_K = Temp + 373;
  Serial.println("C: ");
  Serial.println(Temp);
  Serial.print("F: ");
  Serial.println(Temp_F);
  Serial.print("K: ");
  Serial.println(Temp_K);
  delay(500);
}