#include <servoRun.h>
//Takes input over Serial Command

#include <Servo.h>



//Extra Items
int PanPin;
int TiltPin;
int Camera1Pin;
int MastPin;

//Steering Servos
int FLServoPin   = 2;
int BLServoPin   = 4;
int FRServoPin   = 7;
int BRServoPin   = 8;

//Motor Speed Pins
int FLMotorPin = 6;
int BLMotorPin = 3;
int FRMotorPin = 9;
int BRMotorPin = 8;

//Motor Direction
int BLMotorDirectionPin = 32;;
int BRMotorDirectionPin = 33;
int isFoward;

int Angle;

int largeServoUpper = 2000;
int largeServoLower = 1000;

//Servos

servoRun FLServo;
servoRun BLServo;
servoRun FRServo;
servoRun BRServo;


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

  
  FLServo.buildServo(FLServoPin,1500);
  FLServo.setBounds(largeServoLower,largeServoUpper);
  BLServo.buildServo(BLServoPin,1500);
  BLServo.setBounds(largeServoLower,largeServoUpper);
  FRServo.buildServo(FRServoPin,1500);
  FRServo.setBounds(largeServoLower,largeServoUpper);
  BRServo.buildServo(BRServoPin,1500);
  BRServo.setBounds(largeServoLower,largeServoUpper);
  
  pinMode(BLMotorDirectionPin,OUTPUT);
  pinMode(BRMotorDirectionPin,OUTPUT);
  
  
  delay(3);
  
  digitalWrite(BLMotorDirectionPin,HIGH);
  digitalWrite(BRMotorDirectionPin,LOW);
  isFoward = 1;
  
  pinMode(FLMotorPin,OUTPUT);
  pinMode(BLMotorPin,OUTPUT);
  pinMode(FRMotorPin,OUTPUT);
  pinMode(BRMotorPin,OUTPUT);
  analogWrite(FLMotorPin,0);
  analogWrite(BLMotorPin,0);
  analogWrite(FRMotorPin,0);
  analogWrite(BRMotorPin,0);
  
}

void loop(){
  
  //Switch Statement taking Identifer/Angle
  //Identifiers 1 - 5 correspond to servos
  //Identifier 6 returns Table
  
  if(dataStart())    //check to see if at start of data packet
  {
    Serial.print(1);
    switchvalue = readData();
    switch(switchvalue){
         
     case 41: //Drive Control
       //Read In values
       fl = readData();
       bl = readData();
       fr = readData();
       br = readData();
       pan = readData();
       tilt = readData();
       power = readData();

       //Set Servo Values
       FLServo.setTarget(fl);
       BLServo.setTarget(bl);
       FRServo.setTarget(fr);
       BRServo.setTarget(br);
       
       //Reverse wheel Direction if signs of power change
       setDirection();
       delay(5);
       break;
     default:
       break;
       
    }
  }
  
  
  //Smoothin Equations
  
  FLServo.updateServo();
  BLServo.updateServo();
  FRServo.updateServo();
  BRServo.updateServo();
  
  delay(18);
  
  
  
      
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
  
  
  
  //loop function 10 time ot until data is found
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
  if(power > 255 || power <-255){power = prevPower;}   //check if power within bounds
  if(power * prevPower <= 1);
       {
         if(power > 0)
            {
              //Foward Wheel Direction
              digitalWrite(BLMotorDirectionPin,HIGH);
              digitalWrite(BRMotorDirectionPin,LOW);
              prevPower = power;
            }  else
            {
              //Reverse Wheel 
              digitalWrite(BLMotorDirectionPin,LOW);
              digitalWrite(BRMotorDirectionPin,HIGH);;
              prevPower = power;
              
            }
            //Use only magnitude of Power
            if(power<0){power=power*-1;}
            
            //Set power of motors
            analogWrite(FLMotorPin,power);
            analogWrite(BLMotorPin,power);
            analogWrite(FRMotorPin,power);
            analogWrite(BRMotorPin,power);                 
       }    
}
