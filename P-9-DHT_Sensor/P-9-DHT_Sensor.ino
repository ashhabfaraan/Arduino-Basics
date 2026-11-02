#include <DHT.h>
#include <DHT_U.h>
#define Type DHT11
int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;
float temp_C;
float temp_F;
float temp_K;
int Delay_Time = 500;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
 humidity = HT.readHumidity();
 temp_C = HT.readTemperature();
 temp_F = ((temp_C) * (9 / 5)) + 32;
 temp_K = temp_C + 273;
 Serial.print("Humidity: ");
 Serial.println(humidity);
 Serial.print("C: ");
 Serial.println(temp_C);
 Serial.print("F: ");
 Serial.println(temp_F);
 Serial.print("K: ");
 Serial.println(temp_K);
 delay(Delay_Time);
}
