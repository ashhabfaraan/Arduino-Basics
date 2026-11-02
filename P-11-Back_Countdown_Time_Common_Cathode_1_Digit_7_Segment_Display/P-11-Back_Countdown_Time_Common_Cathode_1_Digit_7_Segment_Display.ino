int DP = 3;
int C = 4;
int D = 5;
int E = 6;
int B = 7;
int A = 8;
int F = 9;
int G = 10;
int delayTime1 = 1000;
int delayTime2 = 500;
void setup() {
  // put your setup code here, to run once:
  pinMode(DP, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Number 9
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

  delay(delayTime1);
  digitalWrite(DP, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);

  delay(delayTime2);

  // Number 8
  digitalWrite(DP, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

  delay(delayTime1);
  digitalWrite(DP, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);

  delay(delayTime2);

  // Number 7
  digitalWrite(DP, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);

  delay(delayTime1);
  digitalWrite(DP, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);

  delay(delayTime2);

  // Number 6
  digitalWrite(DP, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(G, HIGH);

  delay(delayTime1);
  digitalWrite(DP, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(G, LOW);

  delay(delayTime2);

  // Number 5
  digitalWrite(DP, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

  delay(delayTime1);
  digitalWrite(DP, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);

  delay(delayTime2);

  // Number 4
  digitalWrite(DP, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

  delay(delayTime1);
  digitalWrite(DP, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

  delay(delayTime2);

  // Number 3
  digitalWrite(DP, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(G, HIGH);

  delay(delayTime1);
  digitalWrite(DP, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(G, LOW);

  delay(delayTime2);

  // Number 2
  digitalWrite(DP, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(G, HIGH);

  delay(delayTime1);
  digitalWrite(DP, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(G, LOW);

  delay(delayTime2);

  // Number 1
  digitalWrite(DP, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(B, HIGH);

  delay(delayTime1);
  digitalWrite(DP, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(B, LOW);

  delay(delayTime2);

  // Number 0
  digitalWrite(DP, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);

  delay(delayTime1);
  digitalWrite(DP, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);

  delay(delayTime2);
}
