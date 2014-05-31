
#include "workerall.h"

ArmController::ArmController(QObject *parent) :
    QObject(parent)
{
    //dead zone values for joystick
    //Values are radi

    //DeadZone values
    X1_DEADZONE = 5000;
    Y1_DEADZONE = 5000;
    X2_DEADZONE = 5000;
    Y2_DEADZONE = 5000;

    //Arm Postions
    //Drive
    BASE_DRIVE_POSTION = 1200;
    SHOULDER_DRIVE_POSTION = 1100;
    ELBOW_DRIVE_POSTION = 1900;
    WRIST_DRIVE_POSTION = 1800;
    WRIST_ROTATE_DRIVE_POSTION = 1500;

    //Ready
    BASE_READY_POSTION = 1500;
    SHOULDER_READY_POSTION = 1500;
    ELBOW_READY_POSTION = 1500;
    WRIST_READY_POSTION = 1500;
    WRIST_ROTATE_READY_POSTION = 1500;

    count = 0;
    dataSent = "40/1501/1501/1501/1501/1501/1501/";
}

void ArmController::addWorker(Servo *temp)
{
    //Build list of servos to control
    servoList.append(temp);
}

void ArmController::keyInput(QString data)
{
    //Convert xyz to desired servo angle
}




void ArmController::joystickData(int X1,int Y1,int LT,int X2,int Y2,int RT)
{

    //Dead Zone in joystick
    X1 = deadzoneCheck(X1,X1_DEADZONE);
    Y1 = deadzoneCheck(Y1,Y1_DEADZONE);

    X2 = deadzoneCheck(X2,X2_DEADZONE);
    Y2 = deadzoneCheck(Y2,Y2_DEADZONE);

    //Single Joint Control
    //Joystick 1
    int WristR = X1*45/32157;        //X Axis
    int Elbow = Y1*3/32175;          //Y Axis

    //Joystick 2
    int Base = -X2*3/32175;         //X Axis
    int Shoulder = -Y2*3/32175;     //Y Axis

    //Trigers
    //int Claw = servoList.at(5)->microSeconds;  //Triggers
    int Claw = X1*45/32157;
    int Wrist = -(LT-RT)*10/32175; ;

    //Angle Caluculations
    //TODO

    //TODO Replace Names above with Interger array for for loop
    int x[6];
    x[0] = Base;
    x[1] = Shoulder;
    x[2] = Elbow;
    x[3] = Wrist;
    x[4] = WristR;
    x[5] = Claw;
    qDebug()<<"Claw: " << Claw;

    QString dataPart = "";      //Intialist string to build command
    //Make sure adding values dont make value go outside of bounds - set to zero if it does
    int temp;
    for(int i = 0;i < 7; i++)
    {
        temp = boundCheck(x[i],servoList.at(i));    //bound check
        dataPart += QString::number(temp) + "/";    //build datapack
    }

    //Send DataPack Here
    if (dataSent != dataPart)
    {
        emit Send("40/"+dataPart);      //Arm Control has command Identifer 40
        dataSent = dataPart;
    }else{count++;}


}


void ArmController::timeCheck()
{
    qDebug()<<"received emit";
    emit Send(dataSent);
}



//Create deadzones for joysticks
//JOysticks can be to sensitive and be left on when not touched
int ArmController::deadzoneCheck(int value, int deadzone)
{
    //Check if value is within deadzon
    if((value<deadzone) && (value>-deadzone) )
    {
        value = 0;
    }else{
    // correct values outside fo deadzone - values start from 0
    if(value>deadzone){value = value-deadzone;}
    if(value<-deadzone){value = value+deadzone;}
    }
    return value;
}



//Button Presses
void ArmController::buttonPressed(int a)
{
    Servo* claw = servoList.at(5);          //Servo Corresponding to Claw
    if(a == 3)   //if Y is pressed
    {
        if(claw->lowerBound == claw->microSeconds)      //check if open
        {
            claw->setServoValue(claw->upperBound);      //Close
        } else
        {
            claw->setServoValue(claw->lowerBound);      //Open
        }
    }


}

//Function to check if a value is in bounds f servo // set servo if new
int ArmController::boundCheck(int a, Servo *servo)
{
    //check if value is between bounds
    if((servo->microSeconds + a > servo->upperBound) || (servo->microSeconds + a <  servo->lowerBound) )
    {
        a = 0;
    }
    //if value changed update
    if(a != 0)
    {
        a = servo->microSeconds + a;
        servo->setServoValue(a);
    }else{a = servo->microSeconds;}
    return a;
}


//Reset Arduino
//Also Resets Arm to Ready Postion
//Rover Pc must send commands to move to Ready quickly otherwise will attempt to go back to storage
void ArmController::reset()
{
    toReady();
    //send signal
    emit Send("37/");       //Reset Number

}

void ArmController::storageToReady()
{
    //TODO
    toReady();
    //send signal
    emit Send("50/");
}

void ArmController::readyToDrive()
{
    //TODO
    //Set ServoWorkers
    servoList.at(0)->setServoValue(BASE_DRIVE_POSTION);                //Base
    servoList.at(1)->setServoValue(SHOULDER_DRIVE_POSTION);            //Shoulder
    servoList.at(2)->setServoValue(ELBOW_DRIVE_POSTION);               //Elbow
    servoList.at(3)->setServoValue(WRIST_DRIVE_POSTION);               //Wrist
    servoList.at(4)->setServoValue(WRIST_ROTATE_DRIVE_POSTION);        //Wrist Rotate
    servoList.at(5)->setServoValue(servoList.at(5)->upperBound);       //Claw - Closed
    //send signal
    emit Send("51/");

    //New last Data send packet
    dataSent = "40/";
    //Set data Part
    for(int i = 0;i < 6; i++)
    {
        dataSent += QString::number(servoList.at(i)->microSeconds) + "/";    //build datapack
    }
}

void ArmController::driveToReady()
{
    //TODO
    toReady();
    //send signal
    emit Send("52/");
}

void ArmController::toBin()
{
    //TODO
    toReady();
    //send signal
    emit Send("52/");
}

void ArmController::toReady()
{
    //Set ServoWorkers
    servoList.at(0)->setServoValue(BASE_READY_POSTION);                //Base
    servoList.at(1)->setServoValue(SHOULDER_READY_POSTION);            //Shoulder
    servoList.at(2)->setServoValue(ELBOW_READY_POSTION);               //Elbow
    servoList.at(3)->setServoValue(WRIST_READY_POSTION);               //Wrist
    servoList.at(4)->setServoValue(WRIST_ROTATE_READY_POSTION);        //Wrist Rotate
    servoList.at(5)->setServoValue(servoList.at(5)->lowerBound);       //Claw - Closed

    dataSent = "40/";
    //Set data Part
    for(int i = 0;i < 6; i++)
    {
        dataSent += QString::number(servoList.at(i)->microSeconds) + "/";    //build datapack
    }
}

