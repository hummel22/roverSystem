#include <Servo.h>
#include <servoRun.h>  //Custom Library

//Tom update as of 3.15
//MotorPins array
int motorPins[6] = {
  7,8,9,10,11,12};

//Steering Servo Pins
int frontLeftPin = 3;
int frontRightPin = 4;
int backLeftPin = 5;
int backRightPin = 6;

//Min and max servo turns
int largeServoUpper = 2500;
int largeServoLower = 1000;

//Servo Objects
servoRun frontLeft;
servoRun frontRight;
servoRun backLeft;
servoRun backRight;



void setup()
{
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the motorPins as an output:
  for(int i = 0;i<sizeof(motorPins);i++)
  {
    pinMode(motorPins[i],OUTPUT); 
  }
  
   
   //MOTORS OFF -------------------------------------
  for(int i = 0;i<sizeof(motorPins);i++)
  {
    analogWrite(motorPins[i],0); 
  }
  //MOTORS OFF ------------------------------------- //
  //Set starting Locations of Servos and Min/Max
 
  frontLeft.buildServo(frontLeftPin,1700);
  frontRight.buildServo(frontRightPin,1540);
  backLeft.buildServo(backLeftPin,1490);
  backRight.buildServo(backRightPin,1900);
  frontLeft.setBounds(largeServoLower,largeServoLower);
  frontRight.setBounds(largeServoLower,largeServoLower);
  backLeft.setBounds(largeServoLower,largeServoLower);
  backRight.setBounds(largeServoLower,largeServoLower);
}

 void loop ()
{
  // Set all Motors Zero
  Serial.println("Straighten Wheels");  //Wrong SPOT
  
  //MOTORS OFF -------------------------------------
  for(int i = 0;i<sizeof(motorPins);i++)
  {
    analogWrite(motorPins[i],0); 
  }
  //MOTORS OFF ------------------------------------- //
  
  
  
  //WHEELS STRAIGHT -------------------------------------
  backLeft.setTarget(1490);
  backRight.setTarget(1900);
  frontLeft.setTarget(1700);
  frontRight.setTarget(1540);
  //increment wheels until target reached [Smoothing]
  for(int i=0;i<100;i++)
  {
    frontLeft.updateServo();
    frontRight.updateServo();
    backLeft.updateServo();
    backRight.updateServo();
    delay(17);
  }
  //WHEELS STRAIGHT ------------------------------------- //
  
  
  delay(2000);
 
 //front left - lower # = left
 //front right - lower # = left
 
 //MOTORS ON -------------------------------------
  Serial.println("Motors on 60%");
  //increment each motor from 0 to 150
  for(int k = 0;k<150;k++)
  {
    for(int i = 0;i<sizeof(motorPins);i++)
    {
      analogWrite(motorPins[i],k); 
    }
    delay(5);  
  }
  //MOTORS ON ------------------------------------- //
  
  delay(3000);
  
   //MOTORS OFF -------------------------------------
  for(int i = 0;i<sizeof(motorPins);i++)
  {
    analogWrite(motorPins[i],0); 
  }
  //MOTORS OFF ------------------------------------- //
  
  
    //WHEELS LEFT -------------------------------------
  Serial.println("Turn Wheels Left and Move Foward");
  backLeft.setTarget(1190);
  backRight.setTarget(1600);
  frontLeft.setTarget(1400);
  frontRight.setTarget(1240);
  delay(17);
  for(int i=0;i < 100;i++)
  {
    frontLeft.updateServo();
    frontRight.updateServo();
    backLeft.updateServo();
    backRight.updateServo();
    delay(17);
  }
  //WHEELS LEFT ------------------------------------- //

  delay(2000);
  
  
 //WHEELS STRAIGHT -------------------------------------
  backLeft.setTarget(1490);
  backRight.setTarget(1900);
  frontLeft.setTarget(1700);
  frontRight.setTarget(1540);
  //increment wheels until target reached [Smoothing]
  for(int i=0;i<100;i++)
  {
    frontLeft.updateServo();
    frontRight.updateServo();
    backLeft.updateServo();
    backRight.updateServo();
    delay(17);
  }
  //WHEELS STRAIGHT ------------------------------------- //
  
  delay(2000);
  
  //WHEELS right -------------------------------------
  Serial.println("Turn Wheels right and Move Foward");
  backLeft.setTarget(1790);
  backRight.setTarget(2200);
  frontLeft.setTarget(2000);
  frontRight.setTarget(1940);
  delay(17);
  for(int i=0;i < 100;i++)
  {
    frontLeft.updateServo();
    frontRight.updateServo();
    backLeft.updateServo();
    backRight.updateServo();
    delay(17);
  }
  //WHEELS right ------------------------------------- //
  
  delay(10000);
  
}
