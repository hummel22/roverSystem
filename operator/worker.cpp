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
    QObject::connect(SLIDER,SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));
    servoNumber = servo;
    QString send = "WORKER INIT: Servo "+QString::number(servoNumber)+" Created";
    emit toTerminalInternal(send);
    echo = false;
    setServoValue(centerValue);


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

//User changes slider with Controller - Worker Selected
void Servo::joystickData(int x0, int x1, int x2, int x3, int x4, int x5)
{
    int add =-x1*6/32175;
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

        echo = true;
        SLIDER->setValue(map());    //Map MicroSeconds Value to DegreeAngle and set Slider
        sendString = QString::number(servoNumber+1)+"/"+QString::number(microSeconds)+"/";
        emit Send(sendString);


    }
}

//Receive Values from Slider  - Convert Angles to Microsconds
void Servo::sliderChanged(int value)
{
    //This function checks to see if was changed by user OR program
    // If changed by program could send signal twice
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


//change slider to microValue Program Initiaed
void Servo::setServoValue(int microValue)
{

    microSeconds = microValue;
    echo = true;
    SLIDER->setValue(map());    //Map MicroSeconds Value to DegreeAngle and set Slider
    sendString = QString::number(servoNumber+1)+"/"+QString::number(microSeconds)+"/";
    //emit Send(sendString);   //<---- Replace this wil Drive and Arm doing sending
}


//set angle range for graphical window
void Servo::angleRange(int lower, int upper)
{
    lowerAngle = lower;
    upperAngle = upper;
    SLIDER->setRange(lower,upper);
}

//Recenter Value
void Servo::buttonPress(int a)
{
    if(a == 3)      //Press Y to tare
    {
        int radius = centerValue - lowerBound;
        centerValue = microSeconds;
        lowerBound = centerValue - radius;
        upperBound = centerValue + radius;

        //TODO - send tare values to arduino
        emit Send("60/"+QString::number(servoNumber+1)+"/"+QString::number(centerValue)+"/"+QString::number(radius)+"/");
    }
}
