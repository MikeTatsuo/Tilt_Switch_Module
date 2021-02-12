#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define TILT_SWITCH 3

void setup() {
  pinMode(TILT_SWITCH, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print(" Tilt Switch Module");

  lcd.setCursor(0, 2);
  lcd.print("Status:");
}

void loop() {
  lcd.setCursor(8, 2);

  int state = digitalRead(TILT_SWITCH);

  if (state) {
    lcd.print("CLOSED");
  } else {
    lcd.print("OPEN  ");
    delay(200);
  }
}