
#include <Arduino.h>
#include <Time.h>
#include "Feeder.h"
#include <AFMotor.h>

AF_Stepper stepper(48, 2);

Feeder::Feeder() {
    position = stepsToPark;
    mark = millis();
}

void Feeder::feed() {
	Serial.println("Setting feeding to true..");
	feeding = true;
}

void Feeder::feedLoop() {

	if ( feeding == true && ( millis() - mark ) > feedSpeed  ) {

        if ( position < stepsToMax  ) {
            position += step;
            stepper.step(step, BACKWARD, INTERLEAVE);
            mark = millis();
        } else {
            returning = false;
            feeding = false;
            pausing = true;
        }
	}

    if ( returning == true && (millis() - mark ) > returnSpeed  ) {

        if ( position > stepsToPark  ) {
            position -= step;
            stepper.step(step, FORWARD, INTERLEAVE);
            mark = millis();
        } else {
            returning = false;
        }

    }

    // Pause at end of our feed.
    if ( pausing == true && (millis() - mark ) > pauseTime  ) {

        if ( mark > pauseTime ) {
            returning = true;
            pausing = false;
            feeding = false;
        } else {
            mark = millis();
        }

    }
}

void Feeder::loop() {
	feedLoop();
}
