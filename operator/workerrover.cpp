#include "workerrover.h"

RoverController::RoverController(QObject *parent) :
    QObject(parent)
{
    dataSent = "40/1501/1501/1501/1501/1501/1501/0";
}

void RoverController::initialize(QList<Motor*>mot,QList<Servo*> serv)
{

    frontleftSERVO = serv.at(8);
    frontrightSERVO = serv.at(9);
    backleftSERVO = serv.at(10);
    backrightSERVO = serv.at(11);
    panServo = serv.at(6);
    tiltServo = serv.at(7);
    DeadZone = 10000;

}

void RoverController::keyInput(QString data)
{
    //take input (XY) and send to rover
}


//Take Input from Controller and calculate rover values
void RoverController::joystickData(int X1,int Y1,int LT,int X2,int Y2,int RT)
{

    //Remove DeadZone int Right Joystick
    if((X2<DeadZone) && (X2>-DeadZone) )
    {
        X2 = 0;
    }else{
    if(X2>DeadZone){X2 = X2-DeadZone;}
    if(X2<-DeadZone){X2 = X2+DeadZone;}
    }

    if((Y1<DeadZone) && (Y1>-DeadZone) )
    {
        Y1 = 0;
    }else{
    if(Y1>DeadZone){Y1 = Y1-DeadZone;}
    if(Y1<-DeadZone){Y1 = Y1+DeadZone;}
    }

    //Wheel Turn angle
    int valueFront = X2*500/32762+1500;
    int valueBack = -X2*500/32762+1500;
    frontleftSERVO->setServoValue(valueFront);
    frontrightSERVO->setServoValue(valueFront);
    backleftSERVO->setServoValue(valueBack);
    backrightSERVO->setServoValue(valueBack);

    //Power calcautions
    double multiplier1 = (((double)RT)+32767)/(32767*2)+1; //1 to 2
    double multiplier2 = 1-((((double)LT)+32767)*0.5/(32767*2));//From 0.5 to 1
    int pow = -Y1*175/32767 * multiplier1*multiplier2;

    //Build Send String
    QString frontValue = QString::number(valueFront);
    QString backValue = QString::number(valueBack);
    QString Power = QString::number(-1*pow);
    QString send = "41/"+frontValue+"/"+backValue+"/"+frontValue+"/"+backValue+"/"+frontValue+"/"+backValue+"/"+Power+"/";

    if(send != dataSent)    //Dont send if value same as last send
    {
        emit Send(send);
        dataSent = send;
    }


}

//Calculate and return Microseconds for each Servo - Depreciated Note Used
int RoverController::turnWheel(Servo *servo, int joystickValue)
{
    int add;
    if(joystickValue > 0)            //UpperRange Positive
    {
        add = map(joystickValue,0,32767,servo->centerValue,servo->upperBound);
    } else if(joystickValue < 0)     //LowerRange Negative
    {
        add = map(joystickValue,-32767,0,servo->lowerBound,servo->centerValue);
    }else if(joystickValue == 0)    //Zero Position
    {
        add = 0;
    }else{} //Nothing

    servo->setServoValue(servo->centerValue + add);
    return servo->centerValue + add;
}

//Given a number between Bounds 1 convert to number between bounds2
int RoverController::map(int Value, int upper1, int lower1, int upper2, int lower2)
{

    int mapValue = lower2 + (Value/upper1)*(upper2-lower2);
    return mapValue;

}

void RoverController::timeCheck()
{
    qDebug()<<"received emit";
    emit Send(dataSent);
}
