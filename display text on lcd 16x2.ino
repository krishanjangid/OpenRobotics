#include<LiquidCrystal.h> //Library for LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// LCD pins at which it is attached to the Arduino
int sw=8;
int swread =1;
void setup() //method used to run the source for the one time onlys
{
  pinMode(sw,INPUT_PULLUP);
  lcd.begin(16, 2);//LCD order i.e. 16 columns & 2 rows
  lcd.print("R-CAT ");
  lcd.setCursor(0,1);//setting cursor on LCD
  lcd.print("Hello World!");
  delay(1000);//
}
void loop() 
{
 lcd.noDisplay();
 delay(100);
 lcd.scrollDisplayLeft();
 delay(100); 
}
