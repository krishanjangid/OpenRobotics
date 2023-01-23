//front sensors
int F_trig_left = 2;
int F_echo_left = 3;
int F_trig_Center=4;
int F_echo_Center=5;
int F_trig_right = 6;
int F_echo_right = 7;

//back sensors
int B_trig_left = 16;
int B_echo_left = 17;
int B_trig_Center=4;
int B_echo_Center=5;
int B_trig_right = 18;
int B_echo_right = 19;


//motor pins
int m1a = 8;
int m1b = 9;
int m2a = 10;
int m2b = 11;
int en1 = A1;
int en2 = A2;
long distance1;
long distance2;
long distance3;
int duration1;
int duration2;
int duration3;


void setup() {
// put your setup code here, to run once:
pinMode(m1a, OUTPUT);
pinMode(m1b, OUTPUT);
pinMode(m2a, OUTPUT);
pinMode(m2b, OUTPUT);
//Enable pins
pinMode(en1, OUTPUT);
pinMode(en2, OUTPUT);

pinMode(F_trig_left, OUTPUT);
pinMode(F_echo_left, INPUT);
pinMode(F_trig_Center, OUTPUT);
pinMode(F_echo_Center, INPUT);
pinMode(F_trig_right, OUTPUT);
pinMode(F_echo_right, INPUT);


Serial.begin(9600);
}

void loop() {
//front sensor 
 //1
digitalWrite(F_trig_left, LOW);
delayMicroseconds(5);
digitalWrite(F_trig_left, HIGH);
delayMicroseconds(10);
digitalWrite(F_trig_left, LOW);
//2
digitalWrite(F_trig_Center, LOW);
delayMicroseconds(5);
digitalWrite(F_trig_Center, HIGH);
delayMicroseconds(10);
digitalWrite(F_trig_Center, LOW);
//3
digitalWrite(F_trig_right, LOW);
delayMicroseconds(5);
digitalWrite(F_trig_right, HIGH);
delayMicroseconds(10);
digitalWrite(F_trig_right, LOW);


//1 
duration1 = pulseIn(F_echo_left, HIGH);
distance1 = duration1 * 0.034/2;
//2
duration2 = pulseIn(F_echo_Center, HIGH);
distance2 = duration2 * 0.034/2;
//3
duration3 = pulseIn(F_echo_right, HIGH);
distance3 = duration3 * 0.034/2;

//back sensor
 //1
digitalWrite(B_trig_left, LOW);
delayMicroseconds(5);
digitalWrite(B_trig_left, HIGH);
delayMicroseconds(10);
digitalWrite(B_trig_left, LOW);
//2
digitalWrite(B_trig_Center, LOW);
delayMicroseconds(5);
digitalWrite(B_trig_Center, HIGH);
delayMicroseconds(10);
digitalWrite(B_trig_Center, LOW);
//3
digitalWrite(B_trig_right, LOW);
delayMicroseconds(5);
digitalWrite(B_trig_right, HIGH);
delayMicroseconds(10);
digitalWrite(B_trig_right, LOW);

//1 
duration21 = pulseIn(B_echo_left, HIGH);
distance21 = duration1 * 0.034/2;
//2
duration22 = pulseIn(B_echo_Center, HIGH);
distance22 = duration2 * 0.034/2;
//3
duration23 = pulseIn(B_echo_right, HIGH);
distance23 = duration3 * 0.034/2;

  
if(distance1<=30 || distance2<=30 || distance3<=30 )
{
   analogWrite(en1, 0);
   analogWrite(en2, 0);
   digitalWrite(m1a, LOW);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, LOW);
   digitalWrite(m2b, LOW);
}
else{
  forward();
}

}


void forward()
{
 
  if(distance1<=40 || distance2<=40 || distance3<=40)
{
   analogWrite(en1, 0);
   analogWrite(en2, 0);
   digitalWrite(m1a, LOW);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, LOW);
   digitalWrite(m2b, LOW);
  }
 if(distance1<=30 || distance3<=30 )
{
   analogWrite(en1, 0);
   analogWrite(en2, 0);
   digitalWrite(m1a, LOW);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, LOW);
   digitalWrite(m2b, LOW);
  }
  else
  {
   analogWrite(en1, 200);
   analogWrite(en2, 200);
   digitalWrite(m1a, HIGH);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, HIGH);
   digitalWrite(m2b, LOW);
  }
}

//void backward()
//{
//  if(distance1<=30 || distance2<=30)
//{
//   analogWrite(en1, 0);
//   analogWrite(en2, 0);
//   digitalWrite(m1a, LOW);
//   digitalWrite(m1b, LOW);
//   digitalWrite(m2a, LOW);
//   digitalWrite(m2b, LOW);
//  }
//  else
//  {`
//   analogWrite(en1, 200);
//   analogWrite(en2, 200);
//   digitalWrite(m1a, LOW);
//   digitalWrite(m1b, HIGH);
//   digitalWrite(m2a, LOW);
//   digitalWrite(m2b, HIGH);
//  }
//}
