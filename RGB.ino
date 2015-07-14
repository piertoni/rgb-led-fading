
int R,G,B;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  R=analogRead(A2);
  G=analogRead(A3);
  B=analogRead(A4);
  
  R = map(R, 0, 1023, 0, 255);
  analogWrite(9,R);
  G = map(G, 0, 1023, 0, 255);
  analogWrite(10,G);
  B = map(B, 0, 1023, 0, 255);
  analogWrite(11,B);
  delay(50);
  
}
