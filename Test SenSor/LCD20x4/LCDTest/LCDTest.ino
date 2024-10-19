#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2     // พินสำหรับเซ็นเซอร์ DHT11
#define DHTTYPE DHT11 // ประเภทของ DHT

LiquidCrystal_I2C lcd(39, 20, 4); // เปลี่ยนที่อยู่ I2C เป็น 39
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(20, 4);   // เริ่มต้น LCD โดยระบุจำนวนคอลัมน์และแถว
  lcd.backlight();    // เปิดไฟพื้นหลัง LCD
  dht.begin();        // เริ่มต้นเซ็นเซอร์ DHT11
}

void loop() {
  float h = dht.readHumidity();    // อ่านความชื้น
  float t = dht.readTemperature(); // อ่านอุณหภูมิ

  // ตรวจสอบว่าอ่านค่าได้ถูกต้องหรือไม่
  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.print("Error!");
    return;
  }

  // แสดงผลอุณหภูมิและความชื้น
  lcd.clear(); // เคลียร์หน้าจอ LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C "); // แสดงอุณหภูมิ

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print(" % "); // แสดงความชื้น

  // แสดงอิโมจิ
  lcd.setCursor(0, 2);
  lcd.print("🌡️ "); // อิโมจิสำหรับอุณหภูมิ
  lcd.print("💧 "); // อิโมจิสำหรับความชื้น

  delay(2000); // หน่วงเวลา 2 วินาที
}
