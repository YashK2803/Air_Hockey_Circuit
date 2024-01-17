// C++ code
//
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int p1=0,p2=0;
void setup()
{
    pinMode(8,OUTPUT);
    while(digitalRead(7)==0);
    digitalWrite(8,HIGH);
    lcd.begin(16,2);
    lcd.print("GAME STARTS!");
    delay(2000);
    lcd.clear();
    lcd.print("P1");
    lcd.setCursor(7,0);
    lcd.print("vs");
    lcd.setCursor(14,0);
    lcd.print("P2");
  }
 
  

void loop()
{
  while(digitalRead(7)==0)
  {
  lcd.setCursor(0,1);
  lcd.print(p1);
  lcd.setCursor(14,1);
  lcd.print(p2);
  if(analogRead(A0)>10)
  {
    while(analogRead(A0)!=0);
    p1++;
  }
  if(analogRead(A5)>10)
  {
    while(analogRead(A5)!=0);
    p2++;
  }
  }
  lcd.clear();
  lcd.setCursor(0,0);
  if(p1>p2)
    lcd.print("P1 WINS!");
  else if(p1<p2)
    lcd.print("P2 WINS!");
    else
    lcd.print("TIE");
    digitalWrite(8,LOW);
}