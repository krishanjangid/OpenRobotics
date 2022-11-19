int m1a = 2;
int m1b = 3;
int m2a = 4;
int m2b = 5;
int en1 = 6;
int en2 = 11;
int s1 = 13;
int s2=12;
int s1read;
int s2read;


void setup() {
  // put your setup code here, to run once:
pinMode(m1a, OUTPUT);
pinMode(m1b, OUTPUT);
pinMode(m2a, OUTPUT);
pinMode(m2b, OUTPUT);
pinMode(en1, OUTPUT);
pinMode(en2, OUTPUT);
pinMode(s2, INPUT);
Serial.begin(9600);
pinMode(s1, INPUT);
}
void lturn(){
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}

void loop() {
// put your main code here, to run repeatedly
  analogWrite(en1,70);
  analogWrite(en2,70);
  s1read = digitalRead(s1);
  s2read = digitalRead(s2);
  Serial.print("s1read=");
 Serial.println(s1read);
Serial.print("s2read=");
Serial.println(s2read);
 delay(500);
 if(s1read == 0 )
 
 {
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
  
  
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
 }
  if(s1read == 1 ){
 digitalWrite(m1a, LOW);
 digitalWrite(m1b,HIGH );
 digitalWrite(m2a, LOW);
 digitalWrite(m2b, HIGH);
 delay(1000);
 lturn();
 delay(1000);
 }

}

 
