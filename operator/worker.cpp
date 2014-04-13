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
    centerValue = 1500;
    //QSlider settings
    SLIDER->setRange(lowerAngle,upperAngle);          //set range of slider
    SLIDER->setTracking(true);        //user moves slider manually - fluid
    //Set slide value to current slider value
    microSeconds = centerValue;
    QObject::connect(SLIDER,SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));
    servoNumber = servo;
    QString send = "WORKER INIT: Servo "+QString::number(servoNumber)+" Created";
    emit toTerminalInternal(send);
    echo = false;


}

void Servo::keyboardInput(QString data)
{
    //Detemine key pressed - iterate up and down
    switch (*data.toStdString().c_str())
    {
        case 'w':
            microSeconds++;
            if(microSeconds > upperBound+1)
            {
                microSeconds = upperBound;
            }
            echo = true;
            SLIDER->setValue(map());     //move slider with key presses
            sendString = QString::number(servoNumber+1)+"/"+QString::number(microSeconds)+"/";
            emit Send(sendString);

            break;
        case 's':
            microSeconds = microSeconds--;

            if(microSeconds < lowerBound)
            {
                microSeconds = lowerBound
                        ;
            }
            echo = true;
            SLIDER->setValue(map());
            sendString = QString::number(servoNumber+1)+"/"+QString::number(microSeconds)+"/";
            emit Send(sendString);

            break;
    }



}

//User changes slider with Controller
void Servo::joystickData(int x0, int x1, int x2, int x3, int x4, int x5)
{
    int add =-x1*3/32175;
    if((add != 0) && (((add >0) && (microSeconds < upperBound)) || ((add <0) && (microSeconds > lowerBound))))
        {
        microSeconds += add;
        if(microSeconds>upperBound+1)
        {
            microSeconds = upperBound;

        }
        if(microSeconds<lowerBound)
        {
            microSeconds = lowerBound;
        }

        setServoValue(microSeconds);


    }
}

//Receive Values from Slider  - Convert Angles to Microsconds
void Servo::sliderChanged(int value)
{
    //This function checks to see if was changed by user OR program
    //Program sets echo to true before changing - this nullifies this SLOT

    if(echo == false)   //User moved slider
    {
        //Inverse Degree to Micorseconds
        microSeconds = (int)(lowerBound + (((double)value-lowerAngle)/(upperAngle-lowerAngle))*(upperBound-lowerBound));
        sendString = QString::number(servoNumber+1)+"/"+QString::number(microSeconds)+"/";
        emit Send(sendString);
    }
    echo = false; // return to false

}

//Convert current Microseconds to Degrees
int Servo::map()
{
    return (int)(lowerAngle + (microSeconds-lowerBound) * (upperAngle-lowerAngle) / (upperBound-lowerBound));
}


//change slider to microValue
void Servo::setServoValue(int microValue)
{

    microSeconds = microValue;
    echo = true;
    SLIDER->setValue(map());    //Map MicroSeconds Value to DegreeAngle and set Slider
    sendString = QString::number(servoNumber+1)+"/"+QString::number(microSeconds)+"/";
    //emit Send(sendString);   //<---- Replace this wil Drive and Arm doing sending
}

void Servo::angleRange(int lower, int upper)
{
    SLIDER->setRange(lower,upper);
}
