int led1=3;
int led2=4;
int led3=5;
int led4=6;
int sw =10;
int swread=1;
int count = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(sw,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  swread = digitalRead(sw);
  
  
  if (swread == LOW)
  {
    count++;
  }
    if(count==1)
    {
    digitalWrite(led1,HIGH);
    delay(50);
    digitalWrite(led1,LOW);
    delay(50);
    
    }
    else if(count==2)
    {
      digitalWrite(led2,HIGH);
      delay(50);
      digitalWrite(led2,LOW);
      delay(50);
       
     }
     else if(count==3)
     {
      digitalWrite(led3,HIGH);
      delay(50);
      digitalWrite(led3,LOW);
      delay(50);
      
      }
      else if(count==4)
      {
        digitalWrite(led4,HIGH);
        delay(200);
        digitalWrite(led4,LOW);
        delay(200);
        
        }
        else if(count==5)
        {
          count = 0;
          }
        else
        {
          digitalWrite(led1,LOW);
          digitalWrite(led2,LOW);
          digitalWrite(led3,LOW);
          digitalWrite(led4,LOW);
          }
         
          
    }
     
   
