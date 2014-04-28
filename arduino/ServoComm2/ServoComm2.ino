#include <servoRun.h>
//Takes input over Serial Command

#include <Servo.h>


//Pin Setup
//Arm
int BasePin        = 22;
int ShoulderPin    = 23;
int ElbowPin       = 24;
int WristPin       = 25;
int WristRotatePin = 26;
int ClawPin        = 27;

//Extra Items
int PanPin;
int TiltPin;
int Camera1Pin;
int MastPin;

//Steering Servos
int FLServoPin   = 10;
int BLServoPin   = 12;
int FRServoPin   = 11;
int BRServoPin   = 13;

//Motor Speed Pins
int FLMotorPin = 2;
int MLMotorPin = 4;
int BLMotorPin = 6;
int FRMotorPin = 3;
int MRMotorPin = 5;
int BRMotorPin = 7;

//Motor Direction
int FLMotorDirectionPin = 28;
int MLMotorDirectionPin = 30;
int BLMotorDirectionPin = 32;
int FRMotorDirectionPin = 29;
int MRMotorDirectionPin = 31;
int BRMotorDirectionPin = 33;
int isFoward;

int Angle;

int largeServoUpper = 2000;
int largeServoLower = 1000;

//Servos
servoRun Base;
servoRun Shoulder;
servoRun Elbow;
servoRun Wrist;
servoRun WristRotate;
servoRun Claw;

servoRun FLServo;
servoRun BLServo;
servoRun FRServo;
servoRun BRServo;
servoRun list[20];

int newAngle;

//Arm Angle place holders
int base;
int shoulder;
int elbow;
int wrist;
int wristrotate;
int claw;

//Drive andle place holders
int fl;
int bl;
int fr;
int br;
int pan;
int tilt;
int power;

int switchvalue;
bool start;
bool looper;

int prevPower;

void setup (){
  Serial.begin(115200);
  
  //Build Pin List
  
  //Build StartList
  
  //Build Motor Pin List  
  //Assigns Servo to pIns
  Base.buildServo(BasePin,1500);
  Base.setBounds(largeServoLower,largeServoUpper);
  Shoulder.buildServo(ShoulderPin,1500);
  Shoulder.setBounds(largeServoLower,largeServoUpper);
  Elbow.buildServo(ElbowPin,1500);
  Elbow.setBounds(largeServoLower,largeServoUpper);
  Wrist.buildServo(WristPin,1500);
  Wrist.setBounds(largeServoLower,largeServoUpper);
  WristRotate.buildServo(WristRotatePin,1500);
  WristRotate.setBounds(largeServoLower,largeServoUpper);
  Claw.buildServo(ClawPin,1500);
  Claw.setBounds(largeServoLower,largeServoUpper);
  
  FLServo.buildServo(FLServoPin,1500);
  FLServo.setBounds(largeServoLower,largeServoUpper);
  BLServo.buildServo(BLServoPin,1500);
  BLServo.setBounds(largeServoLower,largeServoUpper);
  FRServo.buildServo(FRServoPin,1500);
  FRServo.setBounds(largeServoLower,largeServoUpper);
  BRServo.buildServo(BRServoPin,1500);
  BRServo.setBounds(largeServoLower,largeServoUpper);
  
  pinMode(FLMotorDirectionPin,OUTPUT);
  pinMode(MLMotorDirectionPin,OUTPUT);
  pinMode(BLMotorDirectionPin,OUTPUT);
  pinMode(FRMotorDirectionPin,OUTPUT);
  pinMode(MRMotorDirectionPin,OUTPUT);
  pinMode(BRMotorDirectionPin,OUTPUT);
  digitalWrite(FLMotorDirectionPin,HIGH);
  digitalWrite(MLMotorDirectionPin,HIGH);
  digitalWrite(BLMotorDirectionPin,HIGH);
  digitalWrite(FRMotorDirectionPin,LOW);
  digitalWrite(MRMotorDirectionPin,LOW);
  digitalWrite(BRMotorDirectionPin,LOW);
  isFoward = 1;
  
  analogWrite(FLMotorPin,0);
  analogWrite(MLMotorPin,0);
  analogWrite(BLMotorPin,0);
  analogWrite(FRMotorPin,0);
  analogWrite(MRMotorPin,0);
  analogWrite(BRMotorPin,0);
  
}

void loop(){
  
  //Switch Statement taking Identifer/Angle
  //Identifiers 1 - 5 correspond to servos
  //Identifier 6 returns Table
  
  if(dataStart())    //check to see if at start of data packet
  {
    Serial.print("data Front");
    switchvalue = readData();
    Serial.println(switchvalue);
    switch(switchvalue){
      case 1:
        //checks if new angle is within 8 degrees -- memory erros causes random numbers
        newAngle = readData();
        Base.setTarget(newAngle);
        break;
      case 2:
        //checks if new angle is within 8 degrees -- memory erros causes random numbers
        newAngle = readData();
        //if ( (newAngle>=maxBaseAngle-8) && (newAngle<=maxBaseAngle+8))
        if(true)
        {
          //if it is within -+8 degrees sets new target angle
          Shoulder.setTarget(newAngle);
        }
        break;  
     case 3:
        //checks if new angle is within 8 degrees -- memory erros causes random numbers
        newAngle = readData();
        //if ( (newAngle>=maxBaseAngle-8) && (newAngle<=maxBaseAngle+8))
        if(true)
        {
          //if it is within -+8 degrees sets new target angle
          Elbow.setTarget(newAngle);
        }
        break;
     case 40:
     case 4000:   
     case 4044:
       base = readData();
       shoulder = readData();
       elbow = readData();
       wrist = readData();
       wristrotate = readData();
       claw = readData();
       
       
       Base.setTarget(base);
       Serial.print("Base: ");
       Serial.println(base);
       Shoulder.setTarget(shoulder);
       Elbow.setTarget(elbow);
       Wrist.setTarget(wrist);
       WristRotate.setTarget(wristrotate);
       Claw.setTarget(claw);
       break;
       
     case 41:
       fl = readData();
       bl = readData();
       fr = readData();
       br = readData();
       pan = readData();
       tilt = readData();
       power = readData();

       
       FLServo.setTarget(fl);
       BLServo.setTarget(bl);
       FRServo.setTarget(fr);
       BRServo.setTarget(br);
       
       
       if(power * prevPower <= 1);
       {
         if(power > 0)
            {
              digitalWrite(FLMotorDirectionPin,HIGH);
              digitalWrite(MLMotorDirectionPin,HIGH);
              digitalWrite(BLMotorDirectionPin,HIGH);
              digitalWrite(FRMotorDirectionPin,LOW);
              digitalWrite(MRMotorDirectionPin,LOW);
              digitalWrite(BRMotorDirectionPin,LOW);
              
              
              prevPower = power;
            }  else
            {
              digitalWrite(FLMotorDirectionPin,LOW);
              digitalWrite(MLMotorDirectionPin,LOW);
              digitalWrite(BLMotorDirectionPin,LOW);
              digitalWrite(FRMotorDirectionPin,HIGH);
              digitalWrite(MRMotorDirectionPin,HIGH);
              digitalWrite(BRMotorDirectionPin,HIGH);;
              prevPower = power;
              
            }
            if(power<0){power=power*-1;}
            analogWrite(FLMotorPin,power);
            analogWrite(MLMotorPin,power);
            analogWrite(BLMotorPin,power);
            analogWrite(FRMotorPin,power);
            analogWrite(MRMotorPin,power);
            analogWrite(BRMotorPin,power);
                      
       }
       
       
     default:
       break;
    }
  }
  
  
  //Smoothin Equations
  Shoulder.updateServo();
  Base.updateServo();
  Elbow.updateServo();
  Wrist.updateServo();
  WristRotate.updateServo();
  Claw.updateServo();
  
  FLServo.updateServo();
  BLServo.updateServo();
  FRServo.updateServo();
  BRServo.updateServo();
  
  delay(17);
  
  
  
      
}


int readData(){
  
  char tempValue[512];
  memset(tempValue,0,512);
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
        returnValue = -111;
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
      return 799;
    }
  }
}

bool dataStart()
{
  int count = 0;
  int value;
  while(true)
 {
   
   if(readData() == -111)  //check to see if charter is '-'
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
