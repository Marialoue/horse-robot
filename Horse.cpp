
#include "Horse.h"

using namespace std;


void Horse::walkFront()
{
    for (i = 45; i < 67; i += 5)
    {
        backRight.write(i);
    }
        for (i = 67; i < 90; i += 5)
    {
        backRight.write(i);
    }

    for (i = 90; i > 45; i -= 5)
    {
        frontLeft.write(i);
        delay(100);
    }

    for (i = 45; i < 90; i += 5)
    {
        backLeft.write(i);
        delay(100);
    }

    for (i = 90; i > 45; i -= 5)
    {
        frontRight.write(i);
        delay(100);
    }
}

void Horse::walkBack()
{
    for (i = 90; i > 45; i -= 5)
    {
        backRight.write(i);
        delay(100);
    }

    for (i = 45; i < 90; i += 5)
    {
        frontLeft.write(i);
        delay(100);
    }

    for (i = 90; i > 45; i -= 5)
    {
        backLeft.write(i);
        delay(100);
    }

    for (i = 45; i < 90; i += 5)
    {
        frontRight.write(i);
        delay(100);
    }
}

void Horse::see()
{
    trigPin = 12;
    echoPin = 13;
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT);  // Sets the echoPin as an Input

    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);

    // Calculating the distance
    distance = duration * 0.034 / 2;

    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
}

void Horse::hear()
{

    analogRightSound = A1; // output
    digitalRightSound = 8; // input
    rightSensorValue = 0;

    analogLeftSound = A0;  // output
    digitalLeftSound = 11; // input
    leftSensorValue = 0;

    pinMode(digitalRightSound, INPUT);
    pinMode(digitalLeftSound, INPUT);

    rightSensorValue = analogRead(analogRightSound);
    Serial.print("AnalogRightSensorValue: ");
    Serial.println(rightSensorValue);
    leftSensorValue = analogRead(analogLeftSound);
    Serial.print("AnalogLeftSensorValue: ");
    Serial.println(leftSensorValue);
}

