#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(34,16,2);
String surname = "Chapcha";

void setup()
{
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  for (int index = 0; index < surname.length(); index++) {
    if (index % 2 == 0) {
      lcd.setCursor(index, 0);
    } else {
      lcd.setCursor(index, 1);
    }
    lcd.print(surname[index]);
  }
}

void loop()
{
}