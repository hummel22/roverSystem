#include <servoRun.h>
//Takes input over Serial Command

#include <Servo.h>


//Set Servo locations
int BasePin = 2;
int ShoulderPin = 3;
int ElbowPin = 4;
int WristPin = 5;
int WristRotatePin = 6;
int ClawPin = 7;
int Angle;

int largeServoUpper = 2000;
int largeServoLower = 1000;
servoRun Base;
servoRun Shoulder;
servoRun Elbow;
servoRun Wrist;
servoRun WristRotate;
servoRun Claw;

int checkError;

int base;
int shoulder;
int elbow;
int wrist;
int wristrotate;
int claw;

int switchvalue;
bool start;
bool looper;

void setup (){
  Serial.begin(115200);
  
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
        checkError = readData();
        //if ( (checkError>=maxShoulderAngle-8) && (checkError<=maxShoulderAngle+8))
        if(true)
        {
          //if it is within -+8 degrees sets new target angle
          Base.setTarget(checkError);
        }
        break;
      case 2:
        //checks if new angle is within 8 degrees -- memory erros causes random numbers
        checkError = readData();
        //if ( (checkError>=maxBaseAngle-8) && (checkError<=maxBaseAngle+8))
        if(true)
        {
          //if it is within -+8 degrees sets new target angle
          Shoulder.setTarget(checkError);
        }
        break;  
     case 3:
        //checks if new angle is within 8 degrees -- memory erros causes random numbers
        checkError = readData();
        //if ( (checkError>=maxBaseAngle-8) && (checkError<=maxBaseAngle+8))
        if(true)
        {
          //if it is within -+8 degrees sets new target angle
          Elbow.setTarget(checkError);
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
       Shoulder.setTarget(shoulder);
       Elbow.setTarget(elbow);
       Wrist.setTarget(wrist);
       WristRotate.setTarget(wristrotate);
       Claw.setTarget(claw);
       break;
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
      }else if(readIn == '-')    //Begining of command
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
