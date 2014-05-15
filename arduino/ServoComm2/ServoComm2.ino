#include <servoRun.h>
//Takes input over Serial Command

#include <Servo.h>


//Pin Location
//Arm
int BASE_PIN        = 22;
int SHOULDER_PIN    = 23;
int ELBOW_PIN       = 24;
int WRIST_PIN       = 25;
int WRIST_ROTATE_PIN = 26;
int CLAW_PIN        = 27;

//Steering Servos
int FRONT_LEFT_SERVO_PIN   = 29;
int BACK_LEFT_SERVO_PIN   = 30;
int FRONT_RIGHT_SERVO_PIN   = 31;
int BACK_RIGHT_SERVO_PIN   = 32;

//Motor Speed Pins
int FRONT_LEFT_MOTOR_PIN = 2;
int MIDDLE_LEFT_MOTOR_PIN = 4;
int BACK_LEFT_MOTOR_PIN = 6;
int FRONT_RIGHT_MOTOR_PIN = 3;
int MIDDLE_RIGHT_MOTOR_PIN = 5;
int BACK_RIGHT_MOTOR_PIN = 7;

//Motor Direction
int LEFT_DIRECTION_PIN = 33;
int RIGHT_DIRECTION_PIN = 34;


//Extra Items
int PAN_TILIT = 10;
int TILT_PIN = 11;

int Camera1Pin;
int MastPin;






int isFoward;  //Used for Direction change

int LARGE_SERVO_UPPER_LIMIT = 2000;
int LARGE_SERVO_LOWER_LIMIT = 1000;

//Servo List
//Arm
servoRun Base;
servoRun Shoulder;
servoRun Elbow;
servoRun Wrist;
servoRun WristRotate;
servoRun Claw;

//Steering
servoRun FLServo;
servoRun BLServo;
servoRun FRServo;
servoRun BRServo;
servoRun PanServo;
servoRun TiltServo;

//Counters to see when last time arm or drive was called
//eliminates uneccesary calls to update servos
int armCount;     
int driveCount;    


int pan;
int tilt;
int power;

int prevPower;  //used i case power is wrongswit

void setup (){
  Serial.begin(115200);
  
  //Build Pin List
  
  //Build StartList
  
  //Build Motor Pin List  
  //Assigns Servo to pIns
  Base.buildServo(BASE_PIN,1500);
  Base.setBounds(LARGE_SERVO_LOWER_LIMIT,LARGE_SERVO_UPPER_LIMIT);
  Shoulder.buildServo(SHOULDER_PIN,1500);
  Shoulder.setBounds(LARGE_SERVO_LOWER_LIMIT,1884);
  Elbow.buildServo(ELBOW_PIN,1500);
  Elbow.setBounds(LARGE_SERVO_LOWER_LIMIT,LARGE_SERVO_UPPER_LIMIT);
  Wrist.buildServo(WRIST_PIN,1500);
  Wrist.setBounds(LARGE_SERVO_LOWER_LIMIT,LARGE_SERVO_UPPER_LIMIT);
  WristRotate.buildServo(WRIST_ROTATE_PIN,1522);
  WristRotate.setBounds(LARGE_SERVO_LOWER_LIMIT,LARGE_SERVO_UPPER_LIMIT);
  Claw.buildServo(CLAW_PIN,1500);
  Claw.setBounds(1025,1733);
  
  FLServo.buildServo(FRONT_LEFT_SERVO_PIN,1500);
  FLServo.setBounds(LARGE_SERVO_LOWER_LIMIT,LARGE_SERVO_UPPER_LIMIT);
  BLServo.buildServo(BACK_LEFT_SERVO_PIN,1500);
  BLServo.setBounds(LARGE_SERVO_LOWER_LIMIT,LARGE_SERVO_UPPER_LIMIT);
  FRServo.buildServo(FRONT_RIGHT_SERVO_PIN,1500);
  FRServo.setBounds(LARGE_SERVO_LOWER_LIMIT,LARGE_SERVO_UPPER_LIMIT);
  BRServo.buildServo(BACK_RIGHT_SERVO_PIN,1500);
  BRServo.setBounds(LARGE_SERVO_LOWER_LIMIT,LARGE_SERVO_UPPER_LIMIT);
  PanServo.buildServo(PAN_TILIT,1500);
  PanServo.setBounds(LARGE_SERVO_LOWER_LIMIT,LARGE_SERVO_UPPER_LIMIT);
  TiltServo.buildServo(TILT_PIN,1500);
  TiltServo.setBounds(LARGE_SERVO_LOWER_LIMIT,LARGE_SERVO_UPPER_LIMIT);
  
  pinMode(LEFT_DIRECTION_PIN,OUTPUT);
  pinMode(RIGHT_DIRECTION_PIN,OUTPUT);
  delay(3);
  digitalWrite(LEFT_DIRECTION_PIN,LOW);
  digitalWrite(RIGHT_DIRECTION_PIN,LOW);
  isFoward = 1;
  driveCount = 0;
  armCount = 0;
  
  analogWrite(FRONT_LEFT_MOTOR_PIN,0);
  analogWrite(MIDDLE_LEFT_MOTOR_PIN,0);
  analogWrite(BACK_LEFT_MOTOR_PIN,0);
  analogWrite(FRONT_RIGHT_MOTOR_PIN,0);
  analogWrite(MIDDLE_RIGHT_MOTOR_PIN,0);
  analogWrite(BACK_RIGHT_MOTOR_PIN,0);
  
}

void loop(){
  
  //Switch Statement taking Identifer/Angle
  //Identifiers 1 - 5 correspond to servos
  //Identifier 6 returns Table
  
  if(dataStart())    //check to see if at start of data packet
  {
    switch(readData()){
      case 1:
        Base.setTarget(readData());
        break;
      case 2:
        Shoulder.setTarget(readData());
        break;  
     case 3:
        Elbow.setTarget(readData());
        break;
     case 4:
        Wrist.setTarget(readData());
        break;
     case 5:
        WristRotate.setTarget(readData());
        break;
     case 6:
        Claw.setTarget(readData());
        break;
     case 7:
        Elbow.setTarget(readData());
        break;
     case 8:
        Elbow.setTarget(readData());
        break;
     case 9:
        Elbow.setTarget(readData());
        break;
     case 10:
        Elbow.setTarget(readData());
        break;
     case 11:
        Elbow.setTarget(readData());
        break;
     case 12:
        Elbow.setTarget(readData());
        break;
     case 13:
        Elbow.setTarget(readData());
        break;
     case 14:
        Elbow.setTarget(readData());
        break;
    
     case 40:
     case 4000:   
     case 4044:
       Base.setTarget(readData());
       Shoulder.setTarget(readData());
       Elbow.setTarget(readData());
       Wrist.setTarget(readData());
       WristRotate.setTarget(readData());
       Claw.setTarget(readData());
       armCount = 0; //reset count on Drive
       break;
       
     case 41: //Drive Control
       //Serial.print("Power: ");
       //Serial.println(power);
       //Set Servo Values
       FLServo.setTarget(readData());
       BLServo.setTarget(readData());
       FRServo.setTarget(readData());
       BRServo.setTarget(readData());
       PanServo.setTarget(readData());
       TiltServo.setTarget(readData());
       power = readData();
       driveCount = 0;//Reset count on drive
       
       //Reverse wheel Direction if signs of power change
       setDirection();
       delay(5);
       break;
     default:
       break;
       
    }
  }
  
  
  //Smoothin Equations
  
  //Update 
  if(armCount < 25)
  {
  Shoulder.updateServo();
  Base.updateServo();
  Elbow.updateServo();
  Wrist.updateServo();
  WristRotate.updateServo();
  Claw.updateServo();
  armCount++;
  }
  
  
  if(driveCount<25)
  {
  FLServo.updateServo();
  BLServo.updateServo();
  FRServo.updateServo();
  BRServo.updateServo();
  PanServo.updateServo();
  TiltServo.updateServo();
  
  driveCount++;
  }
  
  delay(18);
  
  
  
      
}


int readData(){
  
  char tempValue[8];
  memset(tempValue,0,8);
  int returnValue;
  int index = 0;
  int END = 0;
  char readIn; 
  
  //loop counter
  int loopCount = 0;
  //Serial.write('1');
  
  
  
  //loop function 10 times checking for data
  while(loopCount<10)
  {
    //increase counter - only checks for data 10 times before exiting
    loopCount++;
    
    //Check to see if data port is open
    if(Serial.available()>0){
      
      //First initializatin before while loop
      //Assign first value
      readIn = Serial.read();
      if(readIn == '/'){        // '/' is end line for numbers
        END = 1;  
      }else if(readIn == '*')    //Begining of command
      {
        returnValue = -2034;
        return returnValue;
      }
      //combine data to create integers in tempValue
      else{
        tempValue[index] = readIn;        
        index++;
      }   
      
      //Continue Creating Interger until stop Value ('/')
      while(END == 0){
        if(Serial.available()>0){

          //Same as code abve          
          readIn = Serial.read();;
          if(readIn == '/'){
            END = 1;
          }
          else{
            tempValue[index] = readIn;        
            index++;          
          }
        }
      }   
      
      //Convert char array to integer
      returnValue = atoi(tempValue);
      return returnValue;
      break;
    }
    
    //if no data delay - doesnt spam monitor -caused stuttering
    else{
      return -2033;
    }
  }
}

bool dataStart()
{
  int count = 0;
  int value;
  while(true)
 {
   int front = readData();
   //Serial.println(front);
   if(front == -2034)  //check to see if charter is '-'
   {
     return true;
   }
   
   count ++;
   if(count > 9)          //run loop only five times
   {
     return false;
   }
   
   
 } 
}

void setDirection()
{
  if(power > 255 || power <-255){power = prevPower;}
  if(power * prevPower <= 1);
       {
         if(power > 0)
            {
              //Foward Wheel Direction
              digitalWrite(LEFT_DIRECTION_PIN,LOW);
              digitalWrite(RIGHT_DIRECTION_PIN,LOW);
              prevPower = power;
            }  else
            {
              //Reverse Wheel 
              digitalWrite(LEFT_DIRECTION_PIN,HIGH);
              digitalWrite(RIGHT_DIRECTION_PIN,HIGH);
              prevPower = power;
              
            }
            //Use only magnitude of Power
            if(power<0){power=power*-1;}
            
            //Set power of motors
            analogWrite(FRONT_LEFT_MOTOR_PIN,power);
            analogWrite(MIDDLE_LEFT_MOTOR_PIN,power);
            analogWrite(BACK_LEFT_MOTOR_PIN,power);
            analogWrite(FRONT_RIGHT_MOTOR_PIN,power);
            analogWrite(MIDDLE_RIGHT_MOTOR_PIN,power);
            analogWrite(BACK_RIGHT_MOTOR_PIN,power);                 
       }    
}

  
