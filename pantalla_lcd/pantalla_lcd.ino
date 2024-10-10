#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

int del = 500;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop(){
  //lcd.scrollDisplayRight();
  if(Serial.available()){
    delay(del);
    lcd.clear();
    while (Serial.available() > 0) {
      lcd.write(Serial.read());
    }
  }
}