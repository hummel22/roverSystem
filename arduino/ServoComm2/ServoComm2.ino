#include <SPI.h>

#include <servoRun.h>
//Takes input over Serial Command

#include <Servo.h>

int FL = 1578;
int BL = 1238;
int FR = 1647;
int BR = 1288;

//Pin Location
//Arm
int BASE_PIN        = 22;
int SHOULDER_PIN    = 23;
int ELBOW_PIN       = 24;
int WRIST_PIN       = 25;
int WRIST_ROTATE_PIN = 13;
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
int LEFT_DIRECTION_PIN = 8;
int RIGHT_DIRECTION_PIN = 9;


//Extra Items
int PAN_TILIT = 11;
int TILT_PIN = 10;

int Camera1Pin;
int MastPin;






int isFoward;  //Used for Direction change

int LARGE_SERVO_UPPER_LIMIT = 2500;
int LARGE_SERVO_LOWER_LIMIT = 500;

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
int center;
int radius;

int prevPower;  //used i case power is wrongswit

int mastPin = 33;
Servo mast;

void setup (){
  Serial.begin(115200);
  
  //Build Pin List
  mast.attach(mastPin);
  mast.write(180);
  
  //Build StartList
  
  //Build Motor Pin List  
  //Assigns Servo to pIns
  Base.buildServo(BASE_PIN,1948);
  Base.setBounds(LARGE_SERVO_LOWER_LIMIT,LARGE_SERVO_UPPER_LIMIT);
  Shoulder.buildServo(SHOULDER_PIN,1492);
  Shoulder.setBounds(LARGE_SERVO_LOWER_LIMIT,1884);
  Elbow.buildServo(ELBOW_PIN,1191);
  Elbow.setBounds(900,LARGE_SERVO_UPPER_LIMIT);
  Wrist.buildServo(WRIST_PIN,1522);
  Wrist.setBounds(LARGE_SERVO_LOWER_LIMIT,LARGE_SERVO_UPPER_LIMIT);
  WristRotate.buildServo(WRIST_ROTATE_PIN,1230);
  WristRotate.setBounds(LARGE_SERVO_LOWER_LIMIT,LARGE_SERVO_UPPER_LIMIT);
  Claw.buildServo(CLAW_PIN,544);
  Claw.setBounds(300,1700);
  
  int FL = 1578;
  int BL = 1238;
  int FR = 1647;
  int BR = 1288;
  FLServo.buildServo(FRONT_LEFT_SERVO_PIN,FL);
  FLServo.setBounds(FL-500,FL+500);
  BLServo.buildServo(BACK_LEFT_SERVO_PIN,1238);
  BLServo.setBounds(BL-500, FL+500);
  FRServo.buildServo(FRONT_RIGHT_SERVO_PIN,1647);
  FRServo.setBounds(FR-500, FR+500);
  BRServo.buildServo(BACK_RIGHT_SERVO_PIN,1804);
  BRServo.setBounds(BR-500, BR+500);
  PanServo.buildServo(PAN_TILIT,1305);
  PanServo.setBounds(LARGE_SERVO_LOWER_LIMIT,LARGE_SERVO_UPPER_LIMIT);
  TiltServo.buildServo(TILT_PIN,1270);
  TiltServo.setBounds(LARGE_SERVO_LOWER_LIMIT,LARGE_SERVO_UPPER_LIMIT);
  
  pinMode(LEFT_DIRECTION_PIN,OUTPUT);
  pinMode(RIGHT_DIRECTION_PIN,OUTPUT);
  delay(3);
  digitalWrite(LEFT_DIRECTION_PIN,HIGH);
  digitalWrite(RIGHT_DIRECTION_PIN,LOW);
  isFoward = 1;
  driveCount = 0;
  armCount = -25;
  
  
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
        armCount = 0;
        break;
      case 2:
        Shoulder.setTarget(readData());
        armCount = 0;
        break;  
     case 3:
        armCount = 0;
        Elbow.setTarget(readData());
        break;
     case 4:
        armCount = 0;
        Wrist.setTarget(readData());
        break;
     case 5:
        WristRotate.setTarget(readData());
        armCount = 0;
        break;
     case 6:
        Claw.setTarget(readData());
        armCount = 0;
        break;
     case 7:
        PanServo.setTarget(readData());
        driveCount = 0;
        break;
     case 8:
        TiltServo.setTarget(readData());
        driveCount = 0;
        break;
     case 9:
        FLServo.setTarget(readData());
        driveCount = 0;
        break;
     case 10:
        BLServo.setTarget(readData());
        driveCount = 0;
        break;
     case 11:
        FRServo.setTarget(readData());
        driveCount = 0;
        break;
     case 12:
        BRServo.setTarget(readData());
        driveCount = 0;
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
       //Set Servo Values\
      
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
     case 50:
       //Run Macro Storage ti Ready
       //Move 1 - Raise elbow over wheel
       Elbow.forceSet(1773);
       delay(1200);
       //Move 2  -  move arm to front - clear frame
       Base.forceSet(1628);
       delay(1000);
       //Move 3 - move to ready postions
       Base.forceSet(1628);
       Shoulder.forceSet(1407);
       Elbow.forceSet(1418);
       Wrist.forceSet(1407);
       WristRotate.forceSet(1854);
       Claw.forceSet(1500);
       delay(2000);      
       break;
       
     case 51:
       //Run Macro - Ready to Drive
       //Move 1 - fold arm up and above frame
       Base.forceSet(1320);
       Shoulder.forceSet(1066);
       Elbow.forceSet(1218);
       Wrist.forceSet(1610);
       WristRotate.forceSet(1778);
       Claw.forceSet(500);
       delay(2000); 
       //move 2 - place arm right above bucket
       Base.forceSet(1847);
       Elbow.forceSet(1176);
       
       
       break;
     case 52:
       //macro to Ready
       //Move 1 - move arm out of frame
       Base.forceSet(1628);
       delay(500);
       //Move 2 - move to final postion
       Shoulder.forceSet(1407);
       Elbow.forceSet(1418);
       Wrist.forceSet(1407);
       WristRotate.forceSet(1854);
       Claw.forceSet(1500);
       delay(1500);
       break;
     case 53:
       //macro to bin 
       //Move 1 - Pull up arm
       //Run Macro - Ready to Drive
       //Move 1 - fold arm up and above frame
       Shoulder.forceSet(1066);
       Elbow.forceSet(1218);
       Wrist.forceSet(1610);
       WristRotate.forceSet(1778);
       Claw.forceSet(500);
       delay(1800);
       //Move 2 - Arm over Bin       
       Base.forceSet(1320);
       delay(1000);
       //Move 3 - Open Claw
       Claw.forceSet(1500);
       delay(1000);
       //Move 4 - Close Claw
       Claw.forceSet(500);      
       break;
       
     case 55:
        //release mast
        mast.write(0);
        break;
       
     case 60:
       //new tare
       switch(readData()){
       case 1:
          center = readData();
          radius = readData();
          Base.setBounds(center-radius, center + radius);
          break;
        case 2:
          center = readData();
          radius = readData();
          Shoulder.setBounds(center-radius, center + radius);
          break;  
       case 3:
          center = readData();
          radius = readData();
          Elbow.setBounds(center-radius, center + radius);
          break;
       case 4:
          center = readData();
          radius = readData();
          Wrist.setBounds(center-radius, center + radius);;
          break;
       case 5:
          center = readData();
          radius = readData();
          WristRotate.setBounds(center-radius, center + radius);;
          break;
       case 6:
          center = readData();
          radius = readData();
          Claw.setBounds(center-radius, center + radius);
          break;
       case 7:
          center = readData();
          radius = readData();
          PanServo.setBounds(center-radius, center + radius);
          break;
       case 8:
          center = readData();
          radius = readData();
          TiltServo.setBounds(center-radius, center + radius);
          break;
       case 9:
          center = readData();
          radius = readData();
          FLServo.setBounds(center-radius, center + radius);
          break;
       case 10:
          center = readData();
          radius = readData();
          BLServo.setBounds(center-radius, center + radius);
          break;
       case 11:
          center = readData();
          radius = readData();
          FRServo.setBounds(center-radius, center + radius);
          break;
       case 12:
          center = readData();
          radius = readData();
          BRServo.setBounds(center-radius, center + radius);
          break;
       case 13:
          center = readData();
          radius = readData();
          Elbow.setBounds(center-radius, center + radius);
          break;
       case 14:
          center = readData();
          radius = readData();
          Elbow.setBounds(center-radius, center + radius);
          break;
       }
     
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
              //this was low/low, changing to left=high, right=low
              digitalWrite(LEFT_DIRECTION_PIN,HIGH);
              digitalWrite(RIGHT_DIRECTION_PIN,LOW);
              prevPower = power;
            }  else
            {
              //Reverse Wheel 
              //this was high/high, changing to left=low, right=high
              digitalWrite(LEFT_DIRECTION_PIN,LOW);
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

  
