#include <servoRun.h>
//Takes input over Serial Command

#include <Servo.h>


//Set Servo locations
int ShoulderPin = 11;
int BasePin = 9;
int ElbowPin = 6;
int WristPin = 10;
int ClawPin =7;
int Angle;

int largeServoUpper = 2000;
int largeServoLower = 1000;
servoRun Base;
servoRun Shoulder;
servoRun Elbow;

int checkError;


void setup (){
  Serial.begin(9600);
  
  //Assigns Servo to pIns
  
  Base.buildServo(BasePin,1500);
  Base.setBounds(largeServoLower,largeServoUpper);
  Shoulder.buildServo(ShoulderPin,1500);
  Shoulder.setBounds(largeServoLower,largeServoUpper);
  Elbow.buildServo(ElbowPin,1500);
  Elbow.setBounds(largeServoLower,largeServoUpper);
}

void loop(){
  
  //Switch Statement taking Identifer/Angle
  //Identifiers 1 - 5 correspond to servos
  //Identifier 6 returns Table
  switch((int)readData()){
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
      
  }
  //Smoothin Equations
  Shoulder.updateServo();
  //Serial.println("Pin 11");
  //Serial.println(setAngle);
  Base.updateServo();
  //Serial.println(setAngle);
  Serial.println(Elbow.updateServo());
  
  delay(17);
  
  
  
      
}


int readData(){
  
  char tempValue[3];
  int returnValue;
  int index = 0;
  int END = 0;
  char readIn; 
  
  //interger to check loop number
  int checkNumber =0;
  //Serial.write('1');
  //loop function until data is recorded
  while(checkNumber<50)
  {
 
    // Show Connection on Operator - Outputs 1 continuously
    //Serial.pintln(1);
    
    //increase counter - only checks for data 50 times before exiting
    checkNumber++;
    
    //Check For Data and if port is open
    if(Serial.available()>0){
      
      //First initializatin before while loop
      //Assign first value
      readIn = Serial.read();
      // '/' is end line for numbers
      if(readIn == '/'){
        END = 1;  
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
          readIn = Serial.read();
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
      return 7;
    }
  }
}


