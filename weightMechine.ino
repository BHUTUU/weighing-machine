/*
BY: Suman Kumar ~BHUTUU
Program: Weight measurement using load cell and standard out to lcd display
*/
//<<<-------Importing Libraries------->>>//
#include <HX711.h>
#include <LiquidCrystal.h>

//<<<------Definig objects------>>>//
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
HX711 scale;

//<<<----- Definig Variables----->>>//
uint8_t dataPin = 8;
uint8_t clockPin = 9;
uint8_t btnPin = 10;
float a, b;
//<<<----- Push Button ------->>>//
void clearSreen(int row) {
  if(row == 0) {
    lcd.setCursor(0, 0);
    lcd.print("                "); //16 spaces for 16 unit lenth of screen.
    lcd.setCursor(0, 0);
  } else if(row == 1) {
    lcd.setCursor(0, 1);
    lcd.print("                "); //16 spaces for 16 unit length of screen.
    lcd.setCursor(0, 1);
  } else if(row == 10) {
    lcd.setCursor(0, 0);
    lcd.print("                "); //16 spaces for 16 unit length of screen.
    lcd.setCursor(0, 1);
    lcd.print("                "); //16 spaces for 16 unit length of screen.
    lcd.setCursor(0, 0);
  }
}
void buttonCheck() {
  while(true) {
    if(digitalRead(btnPin) == 1) {
      break;
    } else {
      delay(1);
    }
  }
}
void setup() {
  pinMode(btnPin, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12 OUTPUT);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  lcd.begin(16, 2);
  clearSreen(10);
//  lcd.print(__FILE__);
//  delay(500);
  lcd.print("Weighing Machine");
  clearSreen(1);
  lcd.print("By: Suman Kumar");
  delay(1000);
  clearSreen(10);
  lcd.print("<<--Company-->> ");
  clearSreen(1);
  lcd.print("     BHUTUU     ");
  delay(1000);
  clearSreen(10);
  scale.begin(dataPin, clockPin);
  lcd.print("UNITS: ");
  lcd.print(scale.get_units(10));
  delay(200);
  clearSreen(10);
  lcd.print("Empty the scale!");
  lcd.setCursor(0, 1);
  lcd.print("& press button");
  buttonCheck();
  scale.tare();
  clearSreen(10);
  lcd.print("UNITS: ");
  clearSreen(1);
  lcd.print(scale.get_units(10));
  delay(200);
  clearSreen(10);
  lcd.print("Put 60Gram and");
  clearSreen(1);
  lcd.print("press any key!");
  buttonCheck();
  clearSreen(10);
  scale.calibrate_scale(60, 5);
  lcd.print("UNITS: ");
  lcd.print(scale.get_units(10));
  delay(200);
  clearSreen(10);
  lcd.print("  ::::UNITS::::  ");
  clearSreen(1);
}

void loop()
{
  lcd.setCursor(0,1);
  lcd.print("                    ");
//  Serial.print("UNITS: ");
 a = scale.get_units(10);
 b = scale.get_units(10);
  while(true) {
        lcd.setCursor(1, 1);
        b = scale.get_units(10);
        if((a) <  b) {
          if(b > 1000.0) {
            b = b/1000.0;
            lcd.print(b);
            lcd.print(" Kg      ");
          } else {
            lcd.print(b);
            lcd.print(" Grams   ");
          }
        } else if(a > b) {
          if(b > 1000.0) {
            b = b/1000.0;
            lcd.print(b);
            lcd.print(" Kg      ");
          } else {
            lcd.print(b);
            lcd.print(" Grams   ");
          }
        }
  }
  //ignore grammer if measure is 1 gram its woud show grams only.. ah i am to implement this so ignore it!!
//  delay(250);
}
