#ifndef HORSE_H
#define HORSE_H

#pragma once

#include "Arduino.h"
#include "Servo.h"


class Horse
{
private:
    short i;
    // define servos as legs
    Servo backLeft;
    Servo backRight;
    Servo frontLeft;
    Servo frontRight;

public:
    // variables used for ultrasonic sensor in function see()
    short trigPin;
    short echoPin;

    // varialbes used for sound sensors in function hear()
    short duration;
    short distance;
    short analogRightSound;
    short digitalRightSound;
    short rightSensorValue;
    short analogLeftSound;
    short digitalLeftSound;
    short leftSensorValue;

    void walkFront();
    void walkBack();
    void see();
    void hear();
    void stop();
};
#endif