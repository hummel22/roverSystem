#include "joystickinput.h"

joystickInput::joystickInput(QObject *parent) :
    QObject(parent)
{
}

void joystickInput::Initialize()
{
    x[0] = 0;       //Left Joystick Y
    x[1] = 0;       //Left Joystick X
    x[2] = 0;       //Left Trigger
    x[3] = 0;       //Right Joystick Y
    x[4] = 0;       //Right Joystick X
    x[5] = 0;       //Right Trigger
    on = false;     //True if connection has been made
    char name[80];
    buttonReleased = true;
    spacer = 1;     //Counter for recording one x out of y events joystick events (1joystick = 6 events)


    int attempts = 0;
    QString devicePath = "/dev/input/js";
    char* device ;
    while(attempts<15)
    {
        //Device loactions
        QByteArray ba = (devicePath+QString::number(attempts)).toLocal8Bit();
        device = ba.data();
        //Try to Open Device
        if( (fd = open(device, O_RDONLY | O_NONBLOCK)) > 0 )
        {
            ioctl(fd,JSIOCGNAME(80),&name);
            qDebug()<<(QString)name;

            if((QString)name == "Microsoft X-Box 360 pad" )
            {
                on = true;
                attempts = 15;

            }else
            {
                attempts++;
            }
            emit toTerminalInternal("JOY: Device: "+(QString)name);

        }
        else
        {
            emit toTerminalInternal("JOY: Failed to Open");
            attempts++;
        }
    }
    getInput();
    qDebug()<<"End JOYSTICK Initialize";
}

void joystickInput::getInput()
{
    read(fd,&event,sizeof (event));
    event.type &= ~JS_EVENT_INIT;
    if (event.type == JS_EVENT_BUTTON)      //Button Presssed
    {
        if(buttonReleased)      //run on button release
        {
            if(event.value ==1)     //event.value (1 = pressed)(0 = released)
            {
                emit buttonPressed(event.number);
                buttonReleased = false;
            }
        } else if  (event.value ==0)
        {
            buttonReleased = true;
        }
    } else if (event.type == JS_EVENT_AXIS)     //Joystick Movements
    {
        if(event.number < 7)
        {
            x[event.number] = event.value;
            if(spacer == 18)                    //Limit number recording each second
            {
                emit joyStickData(x[0],x[1],x[2],x[3],x[4],x[5]);
                spacer =1;
            }
            spacer++;

        }

    }

}
