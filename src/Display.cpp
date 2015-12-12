

#include "Display.h"
#include <Arduino.h>
#include <Time.h>
#include <LiquidCrystal.h>

// LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/*
    12:16
    11:17
    5:23
    4:25
    3:27
    2:29

    44:9
    45:6

*/

LiquidCrystal lcd(16, 17, 23, 25, 27, 29);

Display::Display() {

}

void Display::init() {
    Serial.begin(9600);
    Serial.println("LCD test with PWM contrast adjustment");

    //analogWrite(6,contrast);
    analogWrite(44,contrast);
    analogWrite(45,brightness);

    lcd.begin(20, 4);
    lcd.print("Annealer Online");
}


void Display::loop() {
}

void Display::clear() {
}

void Display::showExposureTime(float time) {
    lcd.setCursor(0, 1);
    lcd.print("Exposure Time: ");
    lcd.setCursor(15, 1);
    lcd.print("     ");
    lcd.setCursor(15, 1);
    lcd.print(time);
};

void Display::showRpms(int rpms) {
    lcd.setCursor(0, 2);
    lcd.print("RPMS: ");
    lcd.setCursor(15, 2);
    lcd.print("     ");
    lcd.setCursor(15, 2);
    lcd.print(rpms);
};


void Display::showFeedCount(int count) {
    lcd.setCursor(0, 3);
    lcd.print("Feed Count: ");
    lcd.setCursor(15, 3);
    lcd.print("     ");
    lcd.setCursor(15, 3);
    lcd.print(count);

};
