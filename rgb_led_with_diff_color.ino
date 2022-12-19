int blue=A0;
int red=A1;
int gr=A2;
int gl=A3;

void setup() {
  pinMode(blue,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(gr,OUTPUT);
  pinMode(gl,OUTPUT);
}
void loop() {
  
  analogWrite(blue,250);
  analogWrite(gr,250);
  analogWrite(gl,250);
  analogWrite(red,0);
}
