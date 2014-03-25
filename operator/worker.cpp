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
    endPointHigh = 2000;
    endPointLow = 1000;
    startPoint = 1500;
    //QSlider settings
    slidePointer->setRange(lowerValue,upperValue);          //set range of slider
    slidePointer->setTracking(true);        //user moves slider manually - fluid
    //Set slide value to current slider value
    slideValue = startPoint;
    QObject::connect(slidePointer,SIGNAL(valueChanged(int)),this,SLOT(SliderRecieved(int)));
    servoNumber = servo;
    QString send = "WORKER INIT: Servo "+QString::number(servoNumber)+" Created";
    emit WorkerToTerminalInternal(send);
    echo = false;


}

void Worker::keyInput(QString data)
{
    //Detemine key pressed - iterate up and down
    switch (*data.toStdString().c_str())
    {
        case 'w':
            slideValue++;
            if(slideValue > endPointHigh+1)
            {
                slideValue = endPointHigh;
            }
            echo = true;
            slidePointer->setValue(map());     //move slider with key presses
            send = QString::number(servoNumber+1)+"/"+QString::number(slideValue)+"/";
            emit WorkerToSend(send);

            break;
        case 's':
            slideValue = slideValue--;

            if(slideValue < endPointLow)
            {
                slideValue = endPointLow
                        ;
            }
            echo = true;
            slidePointer->setValue(map());
            send = QString::number(servoNumber+1)+"/"+QString::number(slideValue)+"/";
            emit WorkerToSend(send);

            break;
    }



}

void Worker::joyInput(int x0, int x1, int x2, int x3, int x4, int x5)
{
    int add =-x1*3/32175;
    if((add != 0) && (((add >0) && (slideValue < endPointHigh)) || ((add <0) && (slideValue > endPointLow))))
        {
        slideValue += add;
        if(slideValue>endPointHigh+1)
        {
            slideValue = endPointHigh;

        }
        if(slideValue<endPointLow)
        {
            slideValue = endPointLow;
        }
        echo = true;
        slidePointer->setValue(map());
        send = QString::number(servoNumber+1)+"/"+QString::number(slideValue)+"/";

        //Possible source for double sending-- slider is changed which then initaes extra send
        //Test deleting
        emit WorkerToSend(send);

    }
}

void Worker::SliderRecieved(int value)
{
    //
    if(echo == false)
    {
        //Inverse Degree to Micorseconds
        slideValue = (int)(endPointLow + (((double)value-lowerValue)/(upperValue-lowerValue))*(endPointHigh-endPointLow));
        send = QString::number(servoNumber+1)+"/"+QString::number(slideValue)+"/";
        emit WorkerToSend(send);
    }
    echo = false;

}

//Returns Current Angle in Degrees
int Worker::map()
{
    return (int)(lowerValue + (slideValue-endPointLow) * (upperValue-lowerValue) / (endPointHigh-endPointLow));
}

void Worker::sendForce(int microValue)
{
    slideValue = microValue;
    echo = true;
    slidePointer->setValue(map());
    send = QString::number(servoNumber+1)+"/"+QString::number(slideValue)+"/";
    emit WorkerToSend(send);
}
