#include "Arduino.h"
#include "servoRun.h"
#include "Servo.h"

servoRun::servoRun()
{
    //Initialize values
    lowerBound = 500;
    upperBound = 2200;
    filterValue = 0.2;
    targetAngle = 1500;
    currentAngle = 1500;
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
    thisServo.writeMicroseconds(startAngle);
}

void servoRun::setTarget(int angle)
{
    //if(checkclose(angle))
    //{
        targetAngle = angle;
    //}

}

int servoRun::updateServo()
{
    currentAngle = currentAngle +(targetAngle-currentAngle)*filterValue;
    thisServo.writeMicroseconds(currentAngle);
    return(currentAngle);
}

bool servoRun::checkclose(int angle)
{
    int  upper = targetAngle + 15;
    int lower = targetAngle - 15;
    if((angle <= upper) && (angle >= lower))
    {
        return true;
    } else{return false;}
}

