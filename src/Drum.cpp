
#include <Arduino.h>
#include <Time.h>
#include "Drum.h"
#include "AccelStepper.h"

#define X_STEP_PIN 54
#define X_DIR_PIN 55
#define X_ENABLE_PIN 38

int speedPin = 9;

AccelStepper stepper1(1, X_STEP_PIN, X_DIR_PIN);

Drum::Drum() {
    mark = millis();
    speed = 0;
    timer = 0;
    stepCounter = 0;
    actualRotationTime = 0.0;
}

int Drum::getRpms() {
    float rpms = (speed/RPM_RATIO) * -1;
    return rpms;
}

void Drum::start() {
    Serial.println("Starting Drum");
    Serial.println(speed);

    stepper1.setMaxSpeed(8192);
    stepper1.setAcceleration(500);

    stepper1.setEnablePin(X_ENABLE_PIN);
    stepper1.setPinsInverted(false, false, true); //invert logic of enable pin
    stepper1.enableOutputs();
    speed = setRpms();

}

void Drum::stop() {
}

int Drum::setRpms() {
    speed = map(analogRead(speedPin), 0, 1023, 0, -500);
    stepper1.setSpeed(speed);
    return speed;
}

float Drum::getExposureTime() {
    float rpms = getRpms();
    if ( rpms != 0 ) {
        return 60.0/rpms;
    } else {
        return 0.0;
    }
}

void Drum::runLoop() {
    setRpms();
    stepper1.setSpeed(speed);
    stepper1.runSpeed();
}

void Drum::loop() {
    runLoop();
};
