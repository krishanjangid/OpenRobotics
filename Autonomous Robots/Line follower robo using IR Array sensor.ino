//Line follower robo using IR Array sensor.ino
//pin connections 

int m1a = 2;
int m1b = 3;
int m2a = 5;
int m2b = 4;
int en1 = 9;
int en2 = 10;
int s2 = 7;
int s4 = 8;
int s2read;
int s4read;
int s3=11;
int s3read;
int s1 = 12;
int s1read;
int s5 = 13;
int s5read;

void setup() {
  // put your setup code here, to run once:
 
   //Motors pin
pinMode(m1a, OUTPUT);
pinMode(m1b, OUTPUT);
pinMode(m2a, OUTPUT);
pinMode(m2b, OUTPUT);

   //pwm pins
pinMode(en1, OUTPUT);
pinMode(en2, OUTPUT);

  //sensor pin
pinMode(s2, INPUT);
pinMode(s4, INPUT);
pinMode(s3, INPUT);
pinMode(s1, INPUT);
pinMode(s5, INPUT);
}

 
void forward()
{
   analogWrite(en1,70);
 analogWrite(en2,70);

   digitalWrite(m1a, HIGH);
 digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
  
  }

  void lturn()
  {
    analogWrite(en1,30);
    analogWrite(en2,50);
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    }
void Rturn(){
  analogWrite(en1,30);
  analogWrite(en2,40);
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
} 
void stp(){
  analogWrite(en1,0);
  analogWrite(en2,0);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
  }

void loop() {
   //main code to run repeatedly
 analogWrite(en1,70);
 analogWrite(en2,70);

  // Reading sensor value
 s2read = digitalRead(s2);
 s4read = digitalRead(s4);
 s3read = digitalRead(s3);
 s1read = digitalRead(s1);
 s5read = digitalRead(s5);

  //Condition for robot

 if(s1read == 1 && s2read==1 && s3read==0 && s4read==1 && s5read==1)
 
 {
  
 forward();
 
 }
else if(s2read==0 && s3read==1 || s1read==0 && s5read==1 )
{
  
lturn();

}

else if(s4read==0 && s3read==1 || s5read==0 && s1read==1)
{
  
Rturn();

}

else
{
  
stp();

}


  
}
