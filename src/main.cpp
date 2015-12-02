
#include <Arduino.h>
#include <Time.h>
#include <Servo.h>
#include "Feeder.h"

Feeder feeder;
unsigned long mark = millis();;

void setup() {
  Serial.begin(9600);
  feeder.init();
}

void loop() {
    feeder.loop();

    if ( ( millis() - mark) > 10000 )  {
    	mark = millis();
    	//feeder.feed();
    }

}
