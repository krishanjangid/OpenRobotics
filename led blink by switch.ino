int led=4;
int sw =2;
int swread=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(sw,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  swread = digitalRead(sw);
  if (swread == LOW)
  {
    digitalWrite(led,HIGH);
    delay(50);
    digitalWrite(led,LOW);
    delay(50);
    }
    else
   {
    digitalWrite(led,LOW);
    }
   
}
