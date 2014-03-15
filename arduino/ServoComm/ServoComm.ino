#include <servoRun.h>



//Takes input over Serial Command

#include <Servo.h>

Servo Base;
Servo Shoulder;
Servo Elbow;
Servo Wrist;
Servo Claw;

//Set Servo locations
int ShoulderPin = 11;
int BasePin = 9;
int ElbowPin = 6;
int WristPin = 10;
int ClawPin =7;
int Angle;

int maxShoulderAngle = 0;    //target angle
double currentShoulderAngle = 0;  //current Angle - used for smoothing

int maxBaseAngle = 0;
double currentBaseAngle = 0;
int setAngle = 900;  //minimum number of microseconds (

int checkError;


void setup (){
  Serial.begin(9600);
  
  //Assigns Servo to pIns
  Shoulder.attach(ShoulderPin);
  Base.attach(BasePin);
  Wrist.attach(WristPin);
  Claw.attach(ClawPin);
  Elbow.attach(ElbowPin);
  
  Shoulder.writeMicroseconds(900);
  Base.writeMicroseconds(900); 
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
        maxShoulderAngle = checkError;
      }
      break;
    case 2:
      //checks if new angle is within 8 degrees -- memory erros causes random numbers
      checkError = readData();
      //if ( (checkError>=maxBaseAngle-8) && (checkError<=maxBaseAngle+8))
      if(true)
      {
        //if it is within -+8 degrees sets new target angle
        maxBaseAngle = checkError;
      }
      break;
      
  }
  //Smoothin Equations
  currentShoulderAngle = currentShoulderAngle +(maxShoulderAngle-currentShoulderAngle)*0.4;
  setAngle = map(currentShoulderAngle,0,179,900,2000);
  Shoulder.writeMicroseconds(setAngle);
  //Serial.println("Pin 11");
  //Serial.println(setAngle);
  currentBaseAngle = currentBaseAngle +(maxBaseAngle-currentBaseAngle)*0.4;
  setAngle = map(currentBaseAngle,0,179,900,2000);
  Base.writeMicroseconds(setAngle);
  //Serial.println(setAngle);
  
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


