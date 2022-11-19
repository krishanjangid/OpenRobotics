int led1=4;

int sw1 = 3 ;
int sw2 = 2;
int swread = 1;
int swread1 = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(sw1,INPUT_PULLUP);
  pinMode(sw2,INPUT_PULLUP);
}

void loop() {
  swread = digitalRead(sw1);
  swread1 = digitalRead(sw2);
  if(swread==LOW)
  {
    digitalWrite(led1,HIGH);
    delay(200);
   
    }
   if(swread1==LOW)
  {
    digitalWrite(led1,LOW);
    delay(50);
    }
   
}
