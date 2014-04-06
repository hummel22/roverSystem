#include "worker.h"

Servo::Servo(QObject *parent) :
    QObject(parent)
{
}

void Servo::Initialize(QSlider *one,int servo)
{
    //Assign values for class - slider and starting values
    SLIDER = one;
    //Default Limits
    upperAngle = 180;
    lowerAngle = 0;
    upperBound = 2000;
    lowerBound = 1000;
    startPoint = 1500;
    //QSlider settings
    SLIDER->setRange(lowerAngle,upperAngle);          //set range of slider
    SLIDER->setTracking(true);        //user moves slider manually - fluid
    //Set slide value to current slider value
    sliderValue = startPoint;
    QObject::connect(SLIDER,SIGNAL(valueChanged(int)),this,SLOT(SliderChanged(int)));
    servoNumber = servo;
    QString send = "WORKER INIT: Servo "+QString::number(servoNumber)+" Created";
    emit ToTerminalInternal(send);
    echo = false;


}

void Servo::KeyboardInput(QString data)
{
    //Detemine key pressed - iterate up and down
    switch (*data.toStdString().c_str())
    {
        case 'w':
            sliderValue++;
            if(sliderValue > upperBound+1)
            {
                sliderValue = upperBound;
            }
            echo = true;
            SLIDER->setValue(map());     //move slider with key presses
            sendString = QString::number(servoNumber+1)+"/"+QString::number(sliderValue)+"/";
            emit Send(sendString);

            break;
        case 's':
            sliderValue = sliderValue--;

            if(sliderValue < lowerBound)
            {
                sliderValue = lowerBound
                        ;
            }
            echo = true;
            SLIDER->setValue(map());
            sendString = QString::number(servoNumber+1)+"/"+QString::number(sliderValue)+"/";
            emit Send(sendString);

            break;
    }



}

void Servo::JoystickInput(int x0, int x1, int x2, int x3, int x4, int x5)
{
    int add =-x1*3/32175;
    if((add != 0) && (((add >0) && (sliderValue < upperBound)) || ((add <0) && (sliderValue > lowerBound))))
        {
        sliderValue += add;
        if(sliderValue>upperBound+1)
        {
            sliderValue = upperBound;

        }
        if(sliderValue<lowerBound)
        {
            sliderValue = lowerBound;
        }
        echo = true;
        SLIDER->setValue(map());
        sendString = QString::number(servoNumber+1)+"/"+QString::number(sliderValue)+"/";

        //Possible source for double sending-- slider is changed which then initaes extra send
        //Test deleting
        emit Send(sendString);

    }
}

//Receive Values from Slider being changed
void Servo::SliderChanged(int value)
{
    //check to see if Slider changed caused by user or program
    //Program sets echo to true before changing - this nullifies this SLOT

    if(echo == false)   //User moved slider
    {
        //Inverse Degree to Micorseconds
        sliderValue = (int)(lowerBound + (((double)value-lowerAngle)/(upperAngle-lowerAngle))*(upperBound-lowerBound));
        sendString = QString::number(servoNumber+1)+"/"+QString::number(sliderValue)+"/";
        emit Send(sendString);
    }
    echo = false; // return to false

}

//Convert current Microseconds to Degrees
int Servo::map()
{
    return (int)(lowerAngle + (sliderValue-lowerBound) * (upperAngle-lowerAngle) / (upperBound-lowerBound));
}


//change slider to microValue
void Servo::sendForce(int microValue)
{

    sliderValue = microValue;
    echo = true;
    SLIDER->setValue(map());
    sendString = QString::number(servoNumber+1)+"/"+QString::number(sliderValue)+"/";
    emit Send(sendString);
}
