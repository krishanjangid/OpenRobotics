int led = 4;
char data = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0)
  {
    data = Serial.read();
    if(data=='n')
    {
      digitalWrite(led,HIGH);
    }
    
  }

}
