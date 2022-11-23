int trig = 8;
int echo = 9;
int m1a = 2;
int m1b = 3;
int m2a = 4;
int m2b = 5;
int en1 = 6;
int en2 = 11;

long distance;
int duration;

void setup() {
  // put your setup code here, to run once:
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);

pinMode(8, OUTPUT);
pinMode(9, INPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(8, LOW);
delay(2);
digitalWrite(8, HIGH);
delay(1000);
digitalWrite(8, LOW);

duration = pulseIn(9, HIGH);
distance = duration * 0.034/2;

Serial.print("Distance : ");
Serial.print("distance");
Serial.print("cm ");

if(distance<=50)
{
  analogWrite(6, 80);
  analogWrite(11, 80);
  digitalWrite(m1a, HIGH);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, HIGH);
   digitalWrite(m2b, LOW);
  }
 
 if(distance<=40)
{
  analogWrite(6, 60);
  analogWrite(11, 60);
  digitalWrite(m1a, HIGH);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, HIGH);
   digitalWrite(m2b, LOW);
  }
 if(distance<35)
 {
  //backward
  analogWrite(6, 90);
  analogWrite(11, 90);
  digitalWrite(m1a, LOW);
   digitalWrite(m1b, HIGH);
   digitalWrite(m2a, LOW);
   digitalWrite(m2b, HIGH);
    delay(800);
   // right
   analogWrite(6, 0);
   analogWrite(11, 200);
   digitalWrite(m1a, LOW);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, HIGH);
   digitalWrite(m2b, LOW); 
   delay(1000);
   // forward
   analogWrite(6, 100);
  analogWrite(11, 100);
  digitalWrite(m1a, HIGH);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, HIGH);
   digitalWrite(m2b, LOW);
  }

if(distance>60)
{
  analogWrite(6, 100);
  analogWrite(11, 100);
  digitalWrite(m1a, HIGH);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, HIGH);
   digitalWrite(m2b, LOW);
  }



}
