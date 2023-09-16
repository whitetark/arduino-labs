#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  float cel = ((analogRead(A0) * (5.0/1024))-0.5)/0.01;
  float farh = (cel * 9) / 5 + 32;
  lcd.setCursor(0, 0);
  lcd.print(cel);
  lcd.print("C");
  
  lcd.setCursor(0, 1);
  lcd.print(farh);
  lcd.print("F");

  delay(600);
}
