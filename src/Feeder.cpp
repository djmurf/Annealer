
#include <Arduino.h>
#include <Time.h>
#include <Servo.h>
#include "Feeder.h"

void Feeder::init() {
    servo.attach(9);
    servo.write(position);
}

void Feeder::feed() {
	Serial.println("Setting feeding to true..");
	feeding = true;
}

void Feeder::feedLoop() {

	if ( feeding == true && ( millis() - mark ) > speed  ) {

        if ( position <= servoMax  ) {
            position += 1;
            servo.write(position);
            mark = millis();
        } else {
            returning = true;
            feeding = false;
        }
	}

    if ( returning == true && (millis() - mark ) > returnSpeed  ) {

        if ( position >= servoPark  ) {
            position -= 1;
            servo.write(position);
            mark = millis();
        } else {
            returning = false;
        }

    }
}

void Feeder::loop() {
	feedLoop();
}
