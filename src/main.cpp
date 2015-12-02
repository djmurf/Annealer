
#include <Arduino.h>
#include <Time.h>
#include <Servo.h>
#include "Feeder.h"
#include "Drum.h"

Feeder feeder;
Drum drum;
unsigned long mark = millis();;

void setup() {
  Serial.begin(9600);
  //drum.start();
}

void loop() {
    feeder.loop();
    drum.loop();

    if ( ( millis() - mark) > 10000 )  {
    	mark = millis();
    	//feeder.feed();
    }

}
