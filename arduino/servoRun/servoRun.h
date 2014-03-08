#ifndef servoRun_h
#define servoRun_h

#include "Arduino.h"
#include "Servo.h"

class servoRun {
private:
    int upperBound;
    int lowerBound;
    int identifier;
    int pinNumber;
    double filterValue;
    double currentAngle;
    int targetAngle;
    Servo thisServo;
public:
    servoRun();
    void setBounds(int lower,int upper);
    void buildServo(int pin, int startAngle);
    void setTarget(int angle);
    void updateServo();
};





#endif
