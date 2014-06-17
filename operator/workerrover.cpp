#include "workerrover.h"

RoverController::RoverController(QObject *parent) :
    QObject(parent)
{
    dataSent = "41/1501/1501/1501/1200/1501/1501/0";
}

void RoverController::initialize(QList<Motor*>mot,QList<Servo*> serv)
{

    frontleftSERVO = serv.at(8);
    backleftSERVO = serv.at(9);
    frontrightSERVO = serv.at(10);
    backrightSERVO = serv.at(11);

    panServo = serv.at(6);
    tiltServo = serv.at(7);
    DeadZone = 10000;

    //DeadZone values
    X1_DEADZONE = 5000;
    Y1_DEADZONE = 5000;
    X2_DEADZONE = 10000;
    Y2_DEADZONE = 10000;

}

void RoverController::keyInput(QString data)
{
    //take input (XY) and send to rover
}


//Take Input from Controller and calculate rover values
void RoverController::joystickData(int X1,int Y1,int LT,int X2,int Y2,int RT)
{

    //Dead Zone in joystick
    X1 = deadzoneCheck(X1,X1_DEADZONE);
    Y1 = deadzoneCheck(Y1,Y1_DEADZONE);

    X2 = deadzoneCheck(X2,X2_DEADZONE);
    Y2 = deadzoneCheck(Y2,Y2_DEADZONE);

    int STEERING = X2;
    int POWER = Y1;
    int PAN = Y2;
    int TILT = X1;

//    //Wheel Turn angle - X2 - Y2 Right Joystcik
//    int valueFront = X2*500/32762+1500;
//    int valueBack = -X2*500/32762+1500;
//    int backRS = -X2*500/32762+backrightSERVO->centerValue;

    //Power calcautions
    double multiplier1 = (((double)RT)+32767)/(32767*2)+1; //1 to 2
    double multiplier2 = 1-((((double)LT)+32767)*0.7/(32767*2));//From 0.1 to 1
    int pow = POWER*175/32767 * multiplier1*multiplier2;

    STEERING = STEERING*multiplier2;


//    //Left Joystick - Controls Pan Tilit
//    int panValue = X1*500/32762+1500;
//    int tiltValue = -Y1*500/32762+1500;

//    frontleftSERVO->setServoValue(valueFront);
//    frontrightSERVO->setServoValue(valueFront);
//    backleftSERVO->setServoValue(valueBack);
//    backrightSERVO->setServoValue(valueBack);
//    panServo->setServoValue(panValue);
//    tiltServo->setServoValue(tiltValue);



//    //Build Send String
//    QString frontValue = QString::number(valueFront);
//    QString backValue = QString::number(valueBack);
    QString Power = QString::number(-1*pow);
//    QString pan = QString::number(panValue);
//    QString tilt = QString::number(tiltValue);
//    QString backRSstring = QString::number(backRS);
//    QString send = "41/"+frontValue+"/"+backValue+"/"+frontValue+"/"+backRSstring+"/"+pan+"/"+tilt+"/"+Power+"/";


    //TODO - future
    //array
    QString newSend = "41/" + mapJoystickValue(frontleftSERVO,STEERING) + "/";        //Fl
    newSend += mapJoystickValue(backleftSERVO,-STEERING) + "/";                       //BL
    newSend += mapJoystickValue(frontrightSERVO,STEERING) + "/";                      //FR  --BL
    newSend += mapJoystickValue(backrightSERVO,-STEERING) + "/";                      //BR
    newSend += mapJoystickValue(panServo,PAN) + "/";                                  //Pan
    newSend += mapJoystickValue(tiltServo,TILT) + "/";                                //Tilt
    newSend += Power + "/";                                                           //Power


    if(newSend != dataSent)    //Dont send if value same as last send
    {
        emit Send(newSend);
        dataSent = newSend;
    }


}

//Calculate and return Microseconds for each Servo - Depreciated Not Used
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

void RoverController::buttonPress(int x)
{
    switch(x)
    {
    case 0:
        panServo->centerValue = panServo->microSeconds;
        tiltServo->centerValue = tiltServo->microSeconds;
//    case 3:
//        emit Send("37/");
//        break;
//    case 0:
//        emit Send("38/");
//        break;
    }
}


//Create deadzones for joysticks
//JOysticks can be to sensitive and be left on when not touched
int RoverController::deadzoneCheck(int value, int deadzone)
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

QString RoverController::mapJoystickValue(Servo *servo, int joystickValue)
{
    int value = joystickValue*(servo->centerValue - servo->lowerBound)/32762 + servo->centerValue;
    servo->setServoValue(value);
    QString tempString = QString::number(value);
    return tempString;
}

