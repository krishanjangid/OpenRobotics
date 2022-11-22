char data = 0;

void setup()
{
    Serial.begin(9600);
    Serial1.begin(9600);
    pinMode(8, OUTPUT);
}
void loop()
{
   if(Serial1.available() > 0)
   {
      data = Serial1.read();
      if(data == '1')
      {
        Serial.print(data);
        Serial.print("=> LED ON");
        Serial.print("\n");
        /*Serial1.print("LED is ON");
        Serial1.print("\n");*/        
        digitalWrite(8, HIGH);
      }
         
      else if(data == '0')
      {
        Serial.print(data);
        Serial.print("=> LED OFF");
        Serial.print("\n");
        /*Serial1.print("LED is OFF");        
        Serial1.print("\n");*/
        digitalWrite(8, LOW);
      }
   }
}