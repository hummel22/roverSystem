#include "radiolist.h"

linkManager::linkManager(keyWindoe *key, QObject *parent) :
    QObject(parent)
{
    keys = key;
    timer = new QTimer(this);
}

void linkManager::radioReceived(int on)
{
    setConfiguration(on);
}

void linkManager::addSlide(Servo *servo)
{
    Servos.append(servo);
}

void linkManager::addButton(HRadioButton *radiobutton)
{
    RadioButtons.append(radiobutton);
}


//Change Radio Selection With Joystick
void linkManager::buttonPressed(int x)
{
    switch(x)       //Check what button was pressed
    {
        case 1:     //If button was A move foward - A Ranges from 0 to (# of Servos)
        if (CurrentValue < RadioButtons.count())
            {
                CurrentValue++;
            } else
            {
                CurrentValue = 1;
            }
            RadioButtons.at(CurrentValue-1)->setChecked(true);
            break;
        case 2:     //If button was B move Backward
        if (CurrentValue > 1)
            {
                CurrentValue--;
            } else
            {
                CurrentValue = RadioButtons.count();
            }
            RadioButtons.at(CurrentValue-1)->setChecked(true);
            break;


    }
}

void linkManager::setConfiguration(int A)
{
    //Disconnet Input Connections to Servos,Arm,Drive
    //Disconnect Servos
    for(int i = 0;i < Servos.count();i++)
    {
        Servos.at(i)->SLIDER->setEnabled(false);
        disconnect(keys,SIGNAL(sendKey(QString)),Servos.at(i),SLOT(keyboardInput(QString)));
        disconnect(jInput,SIGNAL(joyStickData(int,int,int,int,int,int)),Servos.at(i),SLOT(joystickData(int,int,int,int,int,int)));
        disconnect(Servos.at(i),SIGNAL(Send(QString)),mySocket,SLOT(Send(QString)));
    }
    //Disconnect Arm and Driver
    disconnect(jInput,SIGNAL(joyStickData(int,int,int,int,int,int)),Arm,SLOT(joystickData(int,int,int,int,int,int)));
    disconnect(jInput,SIGNAL(joyStickData(int,int,int,int,int,int)),Drive,SLOT(joystickData(int,int,int,int,int,int)));
    timer->stop();
    disconnect(timer,SIGNAL(timeout()),Arm,SLOT(timeCheck()));
    disconnect(timer,SIGNAL(timeout()),Drive,SLOT(timeCheck()));
    disconnect(jInput,SIGNAL(buttonPressed(int)),Drive,SLOT(buttonPress(int)));


    //Make New Connections
    if(A < Servos.count())        //Single Servo Connection
    {
        Servos.at(A)->SLIDER->setEnabled(true);
        connect(keys,SIGNAL(sendKey(QString)),Servos.at(A),SLOT(keyboardInput(QString)));
        connect(jInput,SIGNAL(joyStickData(int,int,int,int,int,int)),Servos.at(A),SLOT(joystickData(int,int,int,int,int,int)));
        connect(Servos.at(A),SIGNAL(Send(QString)),mySocket,SLOT(Send(QString)));

    } else if(A == Servos.count())    //Arm Control
    {
        qDebug()<<"Arm Radio On: conectin joystick";
        connect(jInput,SIGNAL(joyStickData(int,int,int,int,int,int)),Arm,SLOT(joystickData(int,int,int,int,int,int)));
        //connect clock to timer Off
        QObject::connect(timer,SIGNAL(timeout()),Arm,SLOT(timeCheck()));
        //set timout
        timer->start(1000);

    } else if(A == Servos.count() + 1)    //Rover Control
    {
//        qDebug()<<"Drive On";

//        qDebug()<<"Drive Connected to joystick:";
        connect(jInput,SIGNAL(joyStickData(int,int,int,int,int,int)),Drive,SLOT(joystickData(int,int,int,int,int,int)));
        QObject::connect(timer,SIGNAL(timeout()),Drive,SLOT(timeCheck()));
        //set timout
        timer->start(300);
        connect(jInput,SIGNAL(buttonPressed(int)),Drive,SLOT(buttonPress(int)));
    }

    CurrentValue = A + 1;

}
