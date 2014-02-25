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
            emit toSend((QString)"22");
            emit toInternal((QString)"SWITCH: Ping Checked");
        case 1:
            emit toInternal((QString)"SWITCH: Case 1");
            break;
        case 34:
            emit resetHeader();
            break;
        default:
            emit toInternal((QString)"SWITCH: Default");
    }
}
