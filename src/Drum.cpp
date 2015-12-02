
#include <Arduino.h>
#include <Time.h>
#include "Drum.h"
#include <AFMotor.h>

AF_DCMotor motor(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

Drum::Drum() {
    mark = millis();
    speed = 80;
    motor.setSpeed(speed);
}

void Drum::setSpeed(unsigned int speed) {
    motor.setSpeed(speed);
}

void Drum::start() {
    Serial.println("Starting Drum");
    Serial.println(speed);
    motor.setSpeed(speed);
    motor.run(FORWARD);
}

void Drum::stop() {
    motor.run(RELEASE);
}

void Drum::runLoop() {
}

void Drum::loop() {
    runLoop();
};
