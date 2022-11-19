


int Led1=5;
int Led2=6;
int Sw=2;
int Sw1=3;
int swread=0;
int swread1=0;
void setup() 
{



  // put your setup code here, to run once:
pinMode(Led1,OUTPUT);
pinMode(Led2,OUTPUT);
pinMode(Sw,INPUT_PULLUP);
pinMode(Sw1,INPUT_PULLUP);



}

void loop() {
  swread=digitalRead(Sw);
  swread1=digitalRead(Sw1);
  if(swread == LOW)
  {
    digitalWrite(Led1,HIGH);
 
  }
    else if(swread1 == LOW)
  {
       
       digitalWrite(Led1,LOW);
  
  }
 
}
