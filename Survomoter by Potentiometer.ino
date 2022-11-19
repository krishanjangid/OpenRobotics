#include<Servo.h>
Servo s1;
void setup() {
  s1.attach(3);
}

void loop() {
    float po = analogRead(A2);
    float value = map(po,0,1023,0,180);
    s1.write(value);
   
   
  
}
