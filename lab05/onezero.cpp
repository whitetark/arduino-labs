#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(34,16,2);
String surname = "Чапча";

byte letters[8][8] = {
  {B10001, B10001, B01111, B00001, B00001, B00000, B00000, B00000, },
  {B00000, B01110, B01010, B01110, B01010, B00000, B00000, B00000, },
  {B00000, B01110, B01010, B01010, B01010, B00000, B00000, B00000, },
  {B00000, B01010, B01110, B00010, B00010, B00000, B00000, B00000, },
  {B00000, B01110, B01010, B01110, B01010, B00000, B00000, B00000, },
  {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000, },
  {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000, },
  {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000, },
};

void setup()
{
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  for (int index = 0; index < 8; index++){
    lcd.createChar(index, letters[index]);
  }
  for (int index = 0; index < 8; index++){
    lcd.setCursor(index,0);
    lcd.write(index);
  }
}

void loop()
{
}