#include <Servo.h>
#include <servoRun.h>  //Custom Library


//MotorPins array
int motorPins[6] = {
  7,8,9,10,11,12};
//Specific Wheel straight positions - Allow trimming [Not Used]
int wheelsStraightPositions[4] = {
  1500,1500,1500,1500};
  
//Steering Servo Pins
int frontLeftPin = 3;
int frontRightPin = 4;
int backLeftPin = 5;
int backRightPin = 6;

//Min and max servo turns
int largeServoUpper = 2000;
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
  
  //Set starting Locations of Servos and Min/Max
  frontLeft.buildServo(frontLeftPin,1500);
  frontRight.buildServo(frontRightPin,1500);
  backLeft.buildServo(backLeftPin,1500);
  backRight.buildServo(backRightPin,1500);
  frontLeft.setBounds(largeServoLower,largeServoLower);
  frontRight.setBounds(largeServoLower,largeServoLower);
  backLeft.setBounds(largeServoLower,largeServoLower);
  backRight.setBounds(largeServoLower,largeServoLower);
}

void loop() 
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
  backLeft.setTarget(1500);
  backRight.setTarget(1500);
  frontLeft.setTarget(1500);
  frontRight.setTarget(1500);
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
  
  
  delay(5000);
  
  
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

  
  delay(500);
  
  
  //WHEELS LEFT -------------------------------------
  Serial.println("Turn Wheels Left and Move Foward");
  backLeft.setTarget(1300);
  backRight.setTarget(1300);
  frontLeft.setTarget(1300);
  frontRight.setTarget(1300);
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


  delay(1500);
  
  
  //WHEELS RIGHT -------------------------------------
  Serial.println("Turn Wheels Right Move Foward");
  backLeft.setTarget(1700);
  backRight.setTarget(1700);
  frontLeft.setTarget(1700);
  frontRight.setTarget(1700);
  delay(17);
  for(int i=0;i < 100;i++)
  {
    frontLeft.updateServo();
    frontRight.updateServo();
    backLeft.updateServo();
    backRight.updateServo();
    delay(17);
  }
  //WHEELS RIGHT ------------------------------------- //
  

  delay(1500);

   
  //WHEELS STRAIGHT -------------------------------------
  Serial.println("Turn Wheels Straight and Move Foward");
  backLeft.setTarget(1500);
  backRight.setTarget(1500);
  frontLeft.setTarget(1500);
  frontRight.setTarget(1500);
  for(int i=0;i<100;i++)
  {
    frontLeft.updateServo();
    frontRight.updateServo();
    backLeft.updateServo();
    backRight.updateServo();
    delay(17);
  }
  //WHEELS STRAIGHT ------------------------------------- //
  
  
  delay(1000);
  
  
  //MOTORS OFF -------------------------------------
  Serial.println("Motors to 0%");
  for(int k = 150;k>=0;k--)
  {
    for(int i = 0;i<sizeof(motorPins);i++)
    {
      analogWrite(motorPins[i],k); 
    }
    delay(5);
  }
  //MOTORS OFF ------------------------------------- //
  
  
 
  //WHEELS LEFT -------------------------------------
  Serial.println("Turn Wheels Left");
  backLeft.setTarget(1300);
  backRight.setTarget(1300);
  frontLeft.setTarget(1300);
  frontRight.setTarget(1300);
  delay(17);
  for(int i=0;i < 100;i++)
  {
    frontLeft.updateServo();
    frontRight.updateServo();
    backLeft.updateServo();
    backRight.updateServo();
    delay(17);
  }
  //WHEELS LEFT -------------------------------------//
  
  
  
  //WHEELS RIGHT -------------------------------------
  Serial.println("Turn Wheels Right");
  backLeft.setTarget(1700);
  backRight.setTarget(1700);
  frontLeft.setTarget(1700);
  frontRight.setTarget(1700);
  delay(17);
  for(int i=0;i < 100;i++)
  {
    frontLeft.updateServo();
    frontRight.updateServo();
    backLeft.updateServo();
    backRight.updateServo();
    delay(17);
  }
  //WHEELS RIGHT ------------------------------------- //
  
  
  
  //WHEELS LEFT -------------------------------------
  Serial.println("Turn Wheels Left");
  backLeft.setTarget(1300);
  backRight.setTarget(1300);
  frontLeft.setTarget(1300);
  frontRight.setTarget(1300);
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
  
  
  
  //WHEELS RIGHT -------------------------------------
  Serial.println("Turn Wheels Right");
  backLeft.setTarget(1700);
  backRight.setTarget(1700);
  frontLeft.setTarget(1700);
  frontRight.setTarget(1700);
  delay(17);
  for(int i=0;i < 100;i++)
  {
    frontLeft.updateServo();
    frontRight.updateServo();
    backLeft.updateServo();
    backRight.updateServo();
    delay(17);
  }
  //WHEELS RIGHT ------------------------------------- //
  
  
  
  //WHEELS STRAIGHT -------------------------------------
  Serial.println("Turn Straight");
  backLeft.setTarget(1500);
  backRight.setTarget(1500);
  frontLeft.setTarget(1500);
  frontRight.setTarget(1500);
  for(int i=0;i<100;i++)
  {
    frontLeft.updateServo();
    frontRight.updateServo();
    backLeft.updateServo();
    backRight.updateServo();
    delay(17);
  }
  //WHEELS STRAIGHT ------------------------------------- //


}



