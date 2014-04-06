#include "receiveswitch.h"

receiveSwitch::receiveSwitch(QObject *parent) :
    QObject(parent)
{
}

void receiveSwitch::interpret(QString receive)
{
    data = receive.split('/');
    qDebug() << data[0].toInt();
    switch(data[0].toInt())
    {
        case 0:
            // Respond to Ping from Rover
            emit toSend("22/");     //Command send to Rover
            emit toInternal("SWITCH: Ping Checked");
        case 1:
        if(data.size() == 6)
        {
            for(int i = 0;i<data.size();i++)
            {
                dataInterger[i] = data[i].toInt();
            }
            emit servoAttributes(dataInterger);
        } else
        {
            emit toInternal("SWITCH: ServoAttr - Incomplete");
        }
            break;
        case 34:
            emit resetHeader();
            break;
        default:
            emit toInternal((QString)"SWITCH: Default");
    }
}
