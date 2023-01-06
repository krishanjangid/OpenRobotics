//front sensors
int F_trig_left = 12;
int F_echo_left = 13;
int F_trig_right = 14;
int F_echo_right = 15;
//back sensors
int B_trig_left = 16;
int B_echo_left = 17;
int B_trig_right = 18;
int B_echo_right = 19;
//motor pins
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

pinMode(12, OUTPUT);
pinMode(13, INPUT);
pinMode(14, OUTPUT);
pinMode(15, INPUT);

pinMode(16, OUTPUT);
pinMode(17, INPUT);
pinMode(18, OUTPUT);
pinMode(19, INPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 //1
digitalWrite(12, LOW);
delay(2);
digitalWrite(12, HIGH);
delay(1000);
digitalWrite(12, LOW);
//2
digitalWrite(14, LOW);
delay(2);
digitalWrite(14, HIGH);
delay(1000);
digitalWrite(14, LOW);
//3
digitalWrite(16, LOW);
delay(2);
digitalWrite(16, HIGH);
delay(1000);
digitalWrite(16, LOW);
//4
digitalWrite(18, LOW);
delay(2);
digitalWrite(18, HIGH);
delay(1000);
digitalWrite(18, LOW);
//1 
duration1 = pulseIn(13, HIGH);
distance1 = duration1 * 0.034/2;
//2
duration2 = pulseIn(15, HIGH);
distance2 = duration2 * 0.034/2;
//3
duration3 = pulseIn(17, HIGH);
distance3 = duration3 * 0.034/2;
//4
duration4 = pulseIn(19, HIGH);
distance4 = duration4 * 0.034/2;

forward();
  
if(distance1<=30 || distance2<=30)
{
   analogWrite(6, 0);
   analogWrite(11, 0);
   digitalWrite(m1a, LOW);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, LOW);
   digitalWrite(m2b, LOW);
  }
}
void forward()
{
  if(distance1<=30 || distance2<=30)
{
   analogWrite(6, 0);
   analogWrite(11, 0);
   digitalWrite(m1a, LOW);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, LOW);
   digitalWrite(m2b, LOW);
  }
  else
  {
   analogWrite(6, 200);
   analogWrite(11, 200);
   digitalWrite(m1a, HIGH);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, HIGH);
   digitalWrite(m2b, LOW);
  }
}

void backward()
{
  if(distance1<=30 || distance2<=30)
{
   analogWrite(6, 0);
   analogWrite(11, 0);
   digitalWrite(m1a, LOW);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, LOW);
   digitalWrite(m2b, LOW);
  }
  else
  {
   analogWrite(6, 200);
   analogWrite(11, 200);
   digitalWrite(m1a, LOW);
   digitalWrite(m1b, HIGH);
   digitalWrite(m2a, LOW);
   digitalWrite(m2b, HIGH);
  }
}
