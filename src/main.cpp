
#include <Arduino.h>
#include <Time.h>
#include <Servo.h>
#include "Feeder.h"

Feeder feeder;

int pos = 0;    // variable to store the servo position

int park = 10;
int max = 180;
int position = park;

boolean feeding = true;
boolean returning = false;

unsigned long mark = millis();;
boolean feedCalled = false;

void setup() {
  Serial.begin(9600);
  feeder.init();
}

void loop() {
    feeder.loop();
    if ( ( millis() - mark) > 10000 )  {
    	mark = millis();
    	feeder.feed();
    }
}

