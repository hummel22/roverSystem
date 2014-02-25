#include "worker.h"

Worker::Worker(QObject *parent) :
    QObject(parent)
{
}

void Worker::Initialize(QSlider *one,int servo)
{
    //Assign values for class - slider and starting values
    slidePointer = one;
    slideValue = slidePointer->value();
    slidePointer->setRange(5,175);          //set range of slider
    slidePointer->setTracking(true);        //user moves slider manually - fluid
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
            if(slideValue>176)
            {
                slideValue = 175;
            }
            slidePointer->setValue(slideValue);     //move slider with key presses
            send = QString::number(servoNumber)+"/"+QString::number(slideValue)+"/";
            emit WorkerToSend(send);
            break;
        case 's':
            slideValue = slideValue--;

            if(slideValue<5)
            {
                slideValue = 5;
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
    if((add != 0) && (((add >0) && (slideValue < 175)) || ((add <0) && (slideValue > 5))))
        {
        slideValue += add;
        if(slideValue>176)
        {
            slideValue = 175;

        }
        if(slideValue<5)
        {
            slideValue = 5;
        }
        slidePointer->setValue(slideValue);
        send = QString::number(servoNumber)+"/"+QString::number(slideValue)+"/";
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
