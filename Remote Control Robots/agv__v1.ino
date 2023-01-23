#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16x2 LCD

//for bluetooth
char data = 0;

//motor pins
int m1_1 = 2;
int m1_2 = 3;
int m2_1 = 4;
int m2_2 = 5;

//rgb indication lights
red = 6;
ly = 7;
ry = 8;
blue = 9;

//front ultrasonic sensors
int F_trig_left = 10;
int F_echo_left = 11;
int F_trig_Center=12;
int F_echo_Center=14;
int F_trig_right = 15;
int F_echo_right = 16;

//back ultrasonic sensors
int B_trig_left = 17;
int B_echo_left = 18;
int B_trig_Center=19;
int B_echo_Center=20;
int B_trig_right = 21;
int B_echo_right = 22;

long distance1;
long distance2;
long distance3;
int duration1;
int duration2;
int duration3;

long distance21;
long distance22;
long distance23;
int duration21;
int duration22;
int duration23;

//ir sensors
int Bottom_ir_1 = 23;
int Bir1_read;
int Bottom_ir_2 = 24;
int Bir2_read;


// front ir sensors
int ir1 = 25;
int ir1_read;
int ir2 = 26;
int ir2_read;
int ir3 = 27;
int ir3_read;
int ir4 = 28;
int ir4_read;
int ir5 = 29;
int ir5_read;


void setup() {

lcd.init();                      // initialize the lcd 
lcd.backlight();                // turn on the backlight
lcd.begin(16, 2);               // set number of columns and rows for the LCD

pinMode(m1_1, OUTPUT);
pinMode(m1_2, OUTPUT);
pinMode(m2_1, OUTPUT);
pinMode(m2_2, OUTPUT);


pinMode(F_trig_left,OUTPUT);
pinMode(F_echo_left,INPUT);
pinMode(F_trig_Center,OUTPUT);
pinMode(F_echo_Center,INPUT);
pinMode(F_trig_right,OUTPUT);
pinMode(F_echo_right,INPUT);

pinMode(B_trig_left,OUTPUT);
pinMode(B_echo_left,INPUT);
pinMode(B_trig_Center,OUTPUT);
pinMode(B_echo_Center,INPUT);
pinMode(B_trig_right,OUTPUT);
pinMode(B_echo_right,INPUT);

pinMode(ir1, INPUT);
pinMode(ir2, INPUT);
pinMode(ir3, INPUT);
pinMode(ir4, INPUT);
pinMode(ir5, INPUT);

Serial.begin(9600);
Serial1.begin(9600);
}

void loop() {

  lcd.clear();                   // clear the display
  lcd.setCursor(0, 0);            // set cursor to column 0, row 0
  lcd.print("Hello, World!");

  //ultrasonic sensor trig echo

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

//bluethooth available
  
  if(Serial1.available() > 0)
  {
    data = Serial1.read();
  }
  if(data == 'Forward' || data == 'forward' || data == 'F' || data == 'f' || data == 'FORWARD')
  {
    forward();
  }

  else if(data == 'Backward' || data == 'backward' || data == 'B' || data == 'b' || data == 'BACKWARD')
  {
    backward();
  }
  else if(data == 'Left' || data == 'left' || data == 'L' || data == 'l' || data == 'LEFT')
  {
    left();
  }
  else if(data == 'Right' || data == 'right' || data == 'R' || data == 'r' || data == 'RIGHT')
  {
    right();
  }
  else if(data == 'Stop' || data == 'stop' || data == 'S' || data == 's' || data == 'STOP')
  {
   digitalWrite(m1_1, LOW);
   digitalWrite(m1_2, LOW);
   digitalWrite(m2_1, LOW);
   digitalWrite(m2_2, LOW);
  }
  else
  {
   digitalWrite(m1_1, LOW);
   digitalWrite(m1_2, LOW);
   digitalWrite(m2_1, LOW);
   digitalWrite(m2_2, LOW);
  }
}


//void forward()
//{
// 
//  if(distance1<=40 || distance2<=40 || distance3<=40)
//{
//   analogWrite(en1, 0);
//   analogWrite(en2, 0);
//   digitalWrite(m1a, LOW);
//   digitalWrite(m1b, LOW);
//   digitalWrite(m2a, LOW);
//   digitalWrite(m2b, LOW);
//  }
// if(distance1<=30 || distance3<=30 )
//{
//   analogWrite(en1, 0);
//   analogWrite(en2, 0);
//   digitalWrite(m1a, LOW);
//   digitalWrite(m1b, LOW);
//   digitalWrite(m2a, LOW);
//   digitalWrite(m2b, LOW);
//  }
//  else
//  {
//   analogWrite(en1, 200);
//   analogWrite(en2, 200);
//   digitalWrite(m1a, HIGH);
//   digitalWrite(m1b, LOW);
//   digitalWrite(m2a, HIGH);
//   digitalWrite(m2b, LOW);
//  }
//}

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