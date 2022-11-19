int sw=2;
int led1=3;
int led2=4;
int led3=5;
int led4=6;
int led5=7;
int led6=8;
int swread = 0;
int count=0;
void setup() {
  // put your setup code here, to run once:
pinMode(sw,INPUT_PULLUP);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led6,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  swread=digitalRead(sw);
  if(swread==0)
  { for(int i=0;i<=100;i++)
  {
    start:
    count++;
    digitalWrite(led1,HIGH);
    delay(200);
    digitalWrite(led2,HIGH);
    delay(200);
    digitalWrite(led3,HIGH);
    delay(200);
    digitalWrite(led1,LOW);
  
    digitalWrite(led4,HIGH);
   delay(200);
    digitalWrite(led2,LOW);
    digitalWrite(led5,HIGH);
    delay(200);
    digitalWrite(led3,LOW);
    digitalWrite(led6,HIGH);
    delay(200);
    digitalWrite(led4,LOW);
    delay(200);
    digitalWrite(led5,LOW);
    delay(200);
    digitalWrite(led6,LOW);
    delay(200);
//    if(count>3)
//    {
//      count=0;
//      break;
//    }
    goto start;
  }
  }
  
  
}
