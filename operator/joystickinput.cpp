#include "joystickinput.h"

joystickInput::joystickInput(QObject *parent) :
    QObject(parent)
{
}

void joystickInput::Initialize()
{
    x[0] = 0;
    x[1] = 0;
    x[2] = 0;
    x[3] = 0;
    x[4] = 0;
    x[5] = 0;
    on = false;
    char name[] ="unknown";
    buttonReleased = true;
    spacer = 1;



    char device[] = "/dev/input/js1";
    if( (fd = open(device, O_RDONLY | O_NONBLOCK)) > 0 )
    {
        on = true;
        emit toInternal("JOY: Open Sucessful");
        //ioctl(fd,JSIOCGNAME(256),name);
        //emit toInternal("JOY: Device: "+(QString)name);
        //qDebug()<<(QString)name;
    }
    else
    {
        emit toInternal("JOY: Failed to Open");
    }
    getInput();
    qDebug()<<"End Initialize";
}

void joystickInput::getInput()
{
    read(fd,&event,sizeof (event));
    event.type &= ~JS_EVENT_INIT;
    if (event.type == JS_EVENT_BUTTON)
    {
        if(buttonReleased)
        {
            if(event.value ==1)
            {
                emit buttons(event.number);
                buttonReleased = false;
            }
        } else if  (event.value ==0)
        {
            buttonReleased = true;
        }
    } else if (event.type == JS_EVENT_AXIS)
    {
        if(event.number < 7)
        {
            x[event.number] = event.value;
            if(spacer == 18)
            {
                emit axisSet(x[0],x[1],x[2],x[3],x[4],x[5]);
                spacer =1;
            }
            spacer++;

        }

    }

}
