
#include <Arduino.h>
#include <Time.h>
#include <Servo.h>
#include "Feeder.h"
#include "Drum.h"
#include "Display.h"
#include <SimpleTimer.h>

const int feedSensorPin = 32;
boolean sensorState = false;

SimpleTimer timer;

unsigned long mark = millis();;

Feeder feeder;
Drum drum;
Display display;
boolean magnetPresent();
void updateRpms();
void clear();
void updateFeedCount();
void showExposureTime();

void doFeed();

void setup() {
  feeder.init();
  display.init();
  Serial.begin(9600);
  drum.start();
  pinMode(feedSensorPin, INPUT);
  digitalWrite(feedSensorPin, HIGH);
  timer.setInterval(100, updateRpms);
  timer.setInterval(500, updateFeedCount);
  timer.setInterval(1000, showExposureTime);
}


void loop() {

    if(magnetPresent() && !sensorState) {
        sensorState = true;
        feeder.feed();
    } else if(!magnetPresent() && sensorState) {
        sensorState = false;
    }
    //feeder.loop();
    drum.loop();
    feeder.loop();
    display.loop();
    timer.run();

}

void doFeed() {
    feeder.feed();
}

boolean magnetPresent(){
    return digitalRead(feedSensorPin) == LOW;
}

void updateRpms() {
    display.showRpms(drum.getRpms());
}

void updateFeedCount() {
    display.showFeedCount(feeder.getFeedCount());
}

void showExposureTime() {
    display.showExposureTime(drum.getExposureTime());
}
void clear() {
    //display.clear();
}
