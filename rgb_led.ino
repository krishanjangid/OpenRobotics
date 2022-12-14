int b=A1;//blue
int g=A0;//green
int r=A2;//red

void setup() {
  pinMode(b,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(r,OUTPUT);
  
}
void loop() {
  analogWrite(b,0);//blue
  analogWrite(g,255);
  analogWrite(r,255);
  delay(1000);
  analogWrite(b,255);
  analogWrite(g,0);//green
  analogWrite(r,255);
  delay(1000)
  analogWrite(b,255);
  analogWrite(g,255);
  analogWrite(r,0);//red
  delay(1000)
  
}
