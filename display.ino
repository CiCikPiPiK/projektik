#include "display.h"
#include <Wire.h>
emoji::emoji(){}
Display::Display(){
  lcd.init();
  lcd.clear();         
  lcd.backlight();
}

 void Display::show(int startPoint,int row ,String text){
  lcd.setCursor(startPoint,row);
  lcd.print(text);
}
void Display::show(int row ,String text){
  lcd.setCursor(0,row);
  lcd.print(text);
}
void Display::vanish(){lcd.clear();}
