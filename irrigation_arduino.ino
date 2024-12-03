#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup() {
  Serial.begin(9600);
  lcd.clear();
  lcd.begin();
  lcd.backlight();
  
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  delay(1000);
  //lcd.setCursor(0, 0);
  Serial.println("Irrigation System is ON");  
  lcd.print("IRRIGATION");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM IS ON ");
  lcd.print("");
  delay(2000);
  lcd.clear();
}
 
void loop() {
  //lcd.clear();
  int value = analogRead(A0);
int  moisture_percentage = ( 100 - ( (value/1023.00) * 100 ) );
  Serial.println(moisture_percentage);
  lcd.print("Moisture: ");
  lcd.print(moisture_percentage);
  lcd.print("%");
  delay(500);
  if (moisture_percentage > 60) {
    digitalWrite(2, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Water Pump: OFF ");
  }
  else {
    digitalWrite(2, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Water Pump: ON");
  }
 
  if (moisture_percentage < 45) {
    lcd.setCursor(0, 1);
    lcd.print("Moisture : LOW");
  } 
  else if (moisture_percentage > 45 && moisture_percentage < 60) {
    lcd.setCursor(0, 1);
    lcd.print("Moisture : MID ");
  } 
  else if (moisture_percentage > 60) {
    lcd.setCursor(0, 1);
    lcd.print("Moisture : HIGH ");
  }
  Wire.setClock(10000);
  delay(1000);
  lcd.clear();
}
