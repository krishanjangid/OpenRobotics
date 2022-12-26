#include <PS2X_lib.h>  
#define en1 3  
#define m1a 4 
#define m1b 5 
#define m2a 7 
#define m2b 8 
#define en2 6
int blue=A0;
int red=A1;
int gr=A2;
int gl=A3; 
const int cirdelay = 2000;
int motor_right_speed = 0;
int motor_left_speed = 0;

PS2X ps2x; // create PS2 Controller Class
int error = 0; 
byte type = 0;
byte vibrate = 0;



void setup()
{
  
  //Motors pin
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  //pwm pins
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  //rgb pin

  pinMode(blue,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(gr,OUTPUT);
  pinMode(gl,OUTPUT);
  
  // Start serial communication
  Serial.begin(57600);
  
  error = ps2x.config_gamepad(13,12,10,11, true, true);
  //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
 
  // Check for error
  if(error == 0)
  {
  Serial.println("Found Controller, configured successful");
  }
  else if(error == 1){
  Serial.println("No controller found, check wiring or reset the Arduino");
  }
  else if(error == 2){
  Serial.println("Controller found but not accepting commands");
  }
  else if(error == 3){
  Serial.println("Controller refusing to enter Pressures mode, may not support it.");
  }
  // Check for the type of controller
  type = ps2x.readType();
  switch(type) {
  case 0:
    Serial.println("Unknown Controller type");
    break;
  case 1:
    Serial.println("DualShock Controller Found");
    break;
  case 2:
    Serial.println("GuitarHero Controller Found");
    break;
  }

}
void mix()
{
  red1();
  delay(3000);
  
  blue1();
  delay(3000);
  
  greenl();
  delay(1000);
  greenr();
  delay(1000);
 
}

// Main loop
void loop(){
 if(error == 1) //skip loop if no controller found
  return; 
  
 else { 
    start:
    ps2x.read_gamepad(false, vibrate); 
     
     if(ps2x.Button(PSB_PAD_DOWN))
     {
       analogWrite(en1,200);
       analogWrite(en2,200);
       digitalWrite(m1a, HIGH);
       digitalWrite(m1b, LOW);
       digitalWrite(m2a, HIGH);
       digitalWrite(m2b, LOW);
       Serial.println("Move back");
       redblink();
      }
      // TURN RIGHT
      if(ps2x.Button(PSB_PAD_RIGHT))
      {
         analogWrite(en1,150);
         analogWrite(en2,150);
         digitalWrite(m1a, HIGH);
         digitalWrite(m1b, LOW);
         digitalWrite(m2a, LOW);
         digitalWrite(m2b, HIGH);
         Serial.println("Turn right");
      }
      // TURN LEFT
      if(ps2x.Button(PSB_PAD_LEFT))
      {
        analogWrite(en1,150);
        analogWrite(en2,150);
        digitalWrite(m1a, LOW);
        digitalWrite(m1b, HIGH);
        digitalWrite(m2a, HIGH);
        digitalWrite(m2b, LOW);
        Serial.println("Turn left");
      }
      // MOVE forward
      if(ps2x.Button(PSB_PAD_UP))
      {
         analogWrite(en1,200);
         analogWrite(en2,200);
         digitalWrite(m1a, LOW);
         digitalWrite(m1b, HIGH);
         digitalWrite(m2a, LOW);
         digitalWrite(m2b, HIGH);
         blue1();
         Serial.println("Move forward");
      } 
      if(ps2x.Button(PSB_R1))
      {
         analogWrite(en1,80);
         analogWrite(en2,250);
        digitalWrite(m1a, LOW);
         digitalWrite(m1b, HIGH);
         digitalWrite(m2a, LOW);
         digitalWrite(m2b, HIGH);
        Rgreenblink();
         Serial.println("Move Uturn");
      }

         if(ps2x.Button(PSB_R2))
      {
        
        Rgreenblink();
        
      }
       if(ps2x.Button(PSB_L1))
       {
       analogWrite(en1,250);
       analogWrite(en2,80);
       digitalWrite(m1a, LOW);
       digitalWrite(m1b, HIGH);
       digitalWrite(m2a, LOW);
       digitalWrite(m2b, HIGH); 
       Lgreenblink();
       Serial.println("Move Lturn");
      }  
      
        if(ps2x.Button(PSB_L2))
      {
         
        Lgreenblink();
         
      }
      if(!ps2x.Button(PSB_PAD_DOWN) && !ps2x.Button(PSB_PAD_UP) && !ps2x.Button(PSB_PAD_RIGHT) && !ps2x.Button(PSB_PAD_LEFT) && !ps2x.Button(PSB_L1) && !ps2x.Button(PSB_R1) && !ps2x.Button(PSB_L2) && !ps2x.Button(PSB_R2)) 
      {
        analogWrite(en1,0);
        analogWrite(en2,0);
        red1();
       
      }
       delay(50);
 }
}

void red1()
{
  analogWrite(blue,250);
  analogWrite(gr,250);
  analogWrite(gl,250);
  analogWrite(red,0);
}
void blue1()
{
  analogWrite(blue,0);
  analogWrite(gr,250);
  analogWrite(gl,250);
  analogWrite(red,250);
}

void greenr()
{
  analogWrite(blue,250);
  analogWrite(gr,0);
  analogWrite(gl,250);
  analogWrite(red,250);
}
void greenl()
{
  analogWrite(blue,250);
  analogWrite(gr,250);
  analogWrite(gl,0);
  analogWrite(red,250);
}
void redblink()
{
  analogWrite(blue,250);
  analogWrite(gr,250);
  analogWrite(gl,250);
  analogWrite(red,0);
  delay(80);
  analogWrite(blue,250);
  analogWrite(gr,250);
  analogWrite(gl,250);
  analogWrite(red,250);
}
void srgb()
{
  analogWrite(blue,250);
  analogWrite(gr,250);
  analogWrite(gl,250);
  analogWrite(red,250);
}
void Rgreenblink()
{
  analogWrite(blue,250);
  analogWrite(gr,0);
  analogWrite(gl,250);
  analogWrite(red,250);
  delay(100);
  analogWrite(blue,250);
  analogWrite(gr,250);
  analogWrite(gl,250);
  analogWrite(red,250);
}
void Lgreenblink()
{
  analogWrite(blue,250);
  analogWrite(gr,250);
  analogWrite(gl,0);
  analogWrite(red,250);
  delay(100);
  analogWrite(blue,250);
  analogWrite(gr,250);
  analogWrite(gl,250);
  analogWrite(red,250);
}