#include "workerrover.h"

RoverController::RoverController(QObject *parent) :
    QObject(parent)
{
}

void RoverController::initialize(QList<Motor*>mot,QList<Servo*> serv)
{

    frontleftSERVO = serv.at(8);
    frontrightSERVO = serv.at(9);
    backleftSERVO = serv.at(10);
    backrightSERVO = serv.at(11);
    panServo = serv.at(6);
    tiltServo = serv.at(7);

}

void RoverController::keyInput(QString data)
{
    //take input (XY) and send to rover
}


//Take Input from Controller and calculate rover values
void RoverController::joystickData(int X1,int Y1,int LT,int X2,int Y2,int RT)
{



    int valueFront = X2*500/32762+1500;
    int valueBack = -X2*500/32762+1500;
    frontleftSERVO->setServoValue(valueFront);
    frontrightSERVO->setServoValue(valueFront);
    backleftSERVO->setServoValue(valueBack);
    backrightSERVO->setServoValue(valueBack);

//    qDebug()<<"calculated Turn";
//    double multiplier1 = (((double)RT)+32767)/(32767*2)+1; //1 to 2
//    double multiplier2 = 1-((((double)LT)+32767)*0.5/(32767*2));//From 0.5 to 1
//    int pow = -Y1*36/32767 * multiplier1*multiplier2;
    
    
//    emit powerUpdate(pow);
//    emit Send("41/"+FLWSeconds+"/"+FRWSeconds+"/"+BLWSeconds+"/"+BRWSeconds+"/"+PanSeconds+"/"+TiltSeconds+"/"+QString::number(pow)+"/");

}

//Calculate  and return Microseconds for each Servo
int RoverController::turnWheel(Servo *servo, int joystickValue)
{
    int add;
    qDebug()<<"joystick Value: "+joystickValue;
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

    qDebug()<<"add Value: "+add;
    servo->setServoValue(servo->centerValue + add);
    return servo->centerValue + add;
}

//Given a number between Bounds 1 convert to number between bounds2
int RoverController::map(int Value, int upper1, int lower1, int upper2, int lower2)
{

    int mapValue = lower2 + (Value/upper1)*(upper2-lower2);
    return mapValue;

}
