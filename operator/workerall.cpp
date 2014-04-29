#include "workerall.h"

ArmController::ArmController(QObject *parent) :
    QObject(parent)
{
    DeadZone =5000;
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
    if((X1<DeadZone) && (X1>-DeadZone) )
    {
        X1 = 0;
    }else{
    if(X1>DeadZone){X1 = X1-DeadZone;}
    if(X1<-DeadZone){X1 = X1+DeadZone;}
    }

    //Single Joint Control
    //Joystick 1
    int WristR = X1*45/32157;        //X Axis
    int Elbow = Y1*3/32175;          //Y Axis

    //Joystick 2
    int Base = -X2*3/32175;         //X Axis
    int Shoulder = -Y2*3/32175;     //Y Axis

    //Trigers
    int Claw =-(LT-RT)*10/32175;    //Triggers
    int Wrist = 0;


    //Angle Caluculations
    //TODO

    //TODO Replace Names above with Interger array for for loop
    int x[5];
    x[0] = Base;
    x[1] = Shoulder;
    x[2] = Elbow;
    x[3] = Wrist;
    x[4] = WristR;
    x[5] = Claw;

    QString dataPart = "";      //Intialist string to build command

    //Make sure adding values dont make value go outside of bounds - set to zero if it does
    for(int i = 0;i < 6; i++)
    {

        if(servoList.at(i)->microSeconds + x[i] > servoList.at(i)->upperBound)
        {
            x[i] = 0;
        }else if(servoList.at(i)->microSeconds + x[i] <  servoList.at(i)->lowerBound)
        {
            x[i] = 0;
        }else if(x[i] != 0)
        {
            servoList.at(i)->setServoValue(servoList.at(i)->microSeconds + x[i]);
        }
        dataPart += QString::number(servoList.at(i)->microSeconds) + "/";
    }
    //Send DataPack Here
    if (dataSent != dataPart)
    {
        emit Send("40/"+dataPart);      //Arm Control has command Identifer 40
        dataSent = dataPart;
    }

}


//Resets to 1500 - Used in Beta Testing on reset
void ArmController::reset()
{
    servoList.at(0)->setServoValue(1500);
    servoList.at(1)->setServoValue(1500);
    servoList.at(2)->setServoValue(1500);
    servoList.at(3)->setServoValue(1500);
    servoList.at(4)->setServoValue(1500);
    servoList.at(5)->setServoValue(1500);
}
