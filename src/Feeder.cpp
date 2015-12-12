
#include <Arduino.h>
#include <Time.h>
#include "Feeder.h"
#include "AccelStepper.h"


#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

AccelStepper stepper2(1, Y_STEP_PIN, Y_DIR_PIN); // 1 = Driver

void doReturn();
void testf();

Feeder::Feeder() {
    feedCount = 0;
}

void Feeder::init() {


    stepper2.setMaxSpeed(2048);
    stepper2.setAcceleration(500);
    stepper2.setEnablePin(Y_ENABLE_PIN);
    stepper2.setPinsInverted(false, false, true); //invert logic of enable pin
    stepper2.enableOutputs();
    stepper2.setSpeed(2048);

}

void Feeder::feed() {
	feeding = true;
    returning = false;
    pausing = false;
    stepper2.moveTo(-1800);
}

void Feeder::loop() {

    if ( feeding == true ) {
        stepper2.setSpeed(feedSpeed);
    } else if ( returning == true ) {
        stepper2.setSpeed(returnSpeed);
    }


    if (stepper2.distanceToGo() != 0) {
        stepper2.runSpeedToPosition();

    } else {

        if ( feeding == true ) {
            feeding = false;
            pausing = true;
            feedCount++;
            mark = millis();

        } else if ( pausing == true ) {

            if ( millis() - mark > pauseTime ) {
                pausing = false;
                returning = true;
                stepper2.moveTo(0);
            }
        } else if ( returning == true ) {
            returning = false;
        }

    }

}

int Feeder::getFeedCount() {
    return feedCount;
}
