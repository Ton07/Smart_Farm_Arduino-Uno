#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
byte smile[8] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};
void setup()
{
  lcd.init();                      
  lcd.backlight();                 
  lcd.createChar(0, smile);
  lcd.setCursor(1, 1);             
  lcd.print("***Hello world!***");
  lcd.setCursor(3, 2);             
  lcd.print("  AIThaiGen");
  lcd.write(byte(0));              
}
void loop(){}
