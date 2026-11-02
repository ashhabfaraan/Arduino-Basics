int redPin = 4;
int greenPin = 5;
int bluePin = 6;

String setColor;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(redPin, 124);
  analogWrite(greenPin, 24);
  analogWrite(bluePin, 225);

  setColor = Serial.readString();
  // If I write red in the serial monitor then:
  // setcolor = "red";
  if (setColor == "red\n ") {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
  else if (setColor == "cyan\n")
  {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 100);
    analogWrite(bluePin, 00);
  }
  else{
    Serial.println("Color not Picked.")
  }
}
