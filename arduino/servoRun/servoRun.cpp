#include "Arduino.h"
#include "servoRun.h"
#include "Servo.h"

servoRun::servoRun()
{
    //Initialize values
    lowerBound = 500;
    upperBound = 2200;
    filterValue = 0.4;
    targetAngle = 900;
    currentAngle = 900;
}

//set Bounds for this servo
void servoRun::setBounds(int lower,int upper)
{
    upperBound = upper;
    lowerBound = lower;
}


void servoRun::buildServo(int pin,int startAngle)
{
    thisServo.attach(pin);
    thisServo.writeMicroseconds(900);
}

void servoRun::setTarget(int angle)
{
    targetAngle = angle;
}

void servoRun::updateServo()
{

    currentAngle = currentAngle +(targetAngle-currentAngle)*filterValue;
    thisServo.writeMicroseconds(currentAngle);
}
