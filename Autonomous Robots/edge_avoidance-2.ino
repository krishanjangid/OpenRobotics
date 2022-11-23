int m1a = 2;
int m1b = 3;
int m2a = 4;
int m2b = 5;
int en1 = 6;
int en2 = 11;
int s1 = 9;
int s1read;
int s2 = 8;
int s2read;
void setup() {
  // put your setup code here, to run once:
pinMode(9, INPUT);
pinMode(8, INPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(11, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
s1read = digitalRead(s1);
 s2read = digitalRead(s2);
 Serial.print("s1read=");
 Serial.println(s1read);
 
 Serial.print("s2read=");
 Serial.println(s2read);
 delay(200);
 if (s1read==0 && s2read ==0)
{
//forward
analogWrite(6, 70);
  analogWrite(11, 60);
  digitalWrite(m1a, HIGH);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, LOW);
   digitalWrite(m2b, HIGH);
  }

 if (s1read==1 && s2read ==0)
{

   analogWrite(6, 70);
   analogWrite(11, 70);
   digitalWrite(m1a, LOW);
   digitalWrite(m1b, HIGH);
   digitalWrite(m2a, LOW);
   digitalWrite(m2b, HIGH);
   delay(1000);
   analogWrite(6, 80);
   analogWrite(11, 0);
   digitalWrite(m1a, HIGH );
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, LOW);
   digitalWrite(m2b, LOW);
   delay(1000);
  }
  if (s1read==0 && s2read ==1)
{

   analogWrite(6, 70);
   analogWrite(11, 70);
   digitalWrite(m1a, LOW);
   digitalWrite(m1b, HIGH);
   digitalWrite(m2a, LOW);
   digitalWrite(m2b, HIGH);
   delay(800);
   analogWrite(6, 0);
   analogWrite(11, 80);
   digitalWrite(m1a, LOW);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, HIGH);
   digitalWrite(m2b, LOW);
   
   delay(1000);
  
  }
if (s1read == 1 && s2read == 1)
{
analogWrite(6, 80);
   analogWrite(11, 80);
   digitalWrite(m1a, LOW);
   digitalWrite(m1b, HIGH);
   digitalWrite(m2a, LOW);
   digitalWrite(m2b, HIGH);
   delay(900);
analogWrite(6, 80);
  analogWrite(11, 0);
  digitalWrite(m1a, HIGH);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, LOW);
   digitalWrite(m2b, LOW);
 
  delay(1000);
  
}
}
