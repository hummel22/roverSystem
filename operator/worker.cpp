#include "worker.h"

Worker::Worker(QObject *parent) :
    QObject(parent)
{
}

void Worker::Initialize(QSlider *one,int servo)
{
    //Assign values for class - slider and starting values
    slidePointer = one;
    //Default Limits
    upperValue = 175;
    lowerValue = 5;
    //QSlider settings
    slidePointer->setRange(lowerValue,upperValue);          //set range of slider
    slidePointer->setTracking(true);        //user moves slider manually - fluid
    //Set slide value to current slider value
    slideValue = slidePointer->value();
    QObject::connect(slidePointer,SIGNAL(valueChanged(int)),this,SLOT(SliderRecieved(int)));
    servoNumber = servo;
    QString send = "WORKER INIT: Servo "+QString::number(servoNumber)+" Created";
    emit WorkerToTerminalInternal(send);


}

void Worker::keyInput(QString data)
{
    //Detemine key pressed - iterate up and down
    switch (*data.toStdString().c_str())
    {
        case 'w':
            slideValue++;
            if(slideValue > upperValue+1)
            {
                slideValue = upperValue;
            }
            slidePointer->setValue(slideValue);     //move slider with key presses
            send = QString::number(servoNumber)+"/"+QString::number(slideValue)+"/";
            emit WorkerToSend(send);
            break;
        case 's':
            slideValue = slideValue--;

            if(slideValue < lowerValue)
            {
                slideValue = lowerValue;
            }
            slidePointer->setValue(slideValue);
            send = QString::number(servoNumber)+"/"+QString::number(slideValue)+"/";
            emit WorkerToSend(send);
            break;
    }



}

void Worker::joyInput(int x0, int x1, int x2, int x3, int x4, int x5)
{
    int add =-x1*3/32175;
    if((add != 0) && (((add >0) && (slideValue < upperValue)) || ((add <0) && (slideValue > lowerValue))))
        {
        slideValue += add;
        if(slideValue>upperValue+1)
        {
            slideValue = upperValue;

        }
        if(slideValue<lowerValue)
        {
            slideValue = lowerValue;
        }
        slidePointer->setValue(slideValue);
        send = QString::number(servoNumber)+"/"+QString::number(slideValue)+"/";

        //Possible source for double sending-- slider is changed which then initaes extra send
        //Test deleting
        emit WorkerToSend(send);

    }
}

void Worker::SliderRecieved(int value)
{
    //Send data using just slider
    slideValue = value;
    send = QString::number(servoNumber)+"/"+QString::number(slideValue)+"/";
    emit WorkerToSend(send);
}

//possible not needed
int Worker::map(int angleDegree)
{
    return (int)(angleDegree/(upperValue-lowerValue))+lowerValue;
}
