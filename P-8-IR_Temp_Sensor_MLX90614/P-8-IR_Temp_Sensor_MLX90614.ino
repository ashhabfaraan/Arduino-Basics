#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

float Temp;
float ambientTemp;

void setup() {
  Serial.begin(9600);
  if (!mlx.begin()) {
    Serial.println("Sensor not found. Check wiring.");
    while (1);
  }
}

void loop() {
  Temp = mlx.readObjectTempC();
  ambientTemp = mlx.readAmbientTempC();

  Serial.print("Object: ");
  Serial.print(Temp);
  Serial.print(" C   Ambient: ");
  Serial.print(ambientTemp);
  Serial.println(" C");

  delay(500);
}