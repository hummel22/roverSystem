#include "radiolist.h"

RadioList::RadioList(keyWindoe *key, QObject *parent) :
    QObject(parent)
{
    keys = key;
}

void RadioList::RadioReceive(int on)
{
    setConfiguration(on);
}

void RadioList::addslide(Worker *switcher)
{
    switches.append(switcher);
}

void RadioList::addButton(HRadioButton *rbutton)
{
    rButtons.append(rbutton);
}

void RadioList::forcesync()
{
    QString send = "35/";
    for(int i = 0;i < switches.count();i++)
    {
        send = send + QString::number(switches.at(i)->slideValue)+"/";
    }
    emit toSend(send);
}

void RadioList::axisSet(int x0,int x1,int x2,int x3,int x4,int x5)
{

}


void RadioList::buttons(int x)
{
    switch(x)
    {
        case 1:
        if (CurrentValue < rButtons.count())
            {
                CurrentValue++;
            } else
            {
                CurrentValue = 1;
            }
            rButtons.at(CurrentValue-1)->setChecked(true);
    }
}

void RadioList::setConfiguration(int A)
{

    for(int i = 0;i < switches.count();i++)
    {
        switches.at(i)->slidePointer->setEnabled(false);
        disconnect(keys,SIGNAL(sendKey(QString)),switches.at(i),SLOT(keyInput(QString)));
        disconnect(joys,SIGNAL(axisSet(int,int,int,int,int,int)),switches.at(i),SLOT(joyInput(int,int,int,int,int,int)));
    }
    disconnect(joys,SIGNAL(axisSet(int,int,int,int,int,int)),wAll,SLOT(axisR(int,int,int,int,int,int)));
    disconnect(joys,SIGNAL(axisSet(int,int,int,int,int,int)),rWindow,SLOT(axisSteer(int,int,int,int,int,int)));

    switch(A)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            switches.at(A-1)->slidePointer->setEnabled(true);
            connect(keys,SIGNAL(sendKey(QString)),switches.at(A-1),SLOT(keyInput(QString)));
            connect(joys,SIGNAL(axisSet(int,int,int,int,int,int)),switches.at(A-1),SLOT(joyInput(int,int,int,int,int,int)));
            break;
        case 7:
            connect(joys,SIGNAL(axisSet(int,int,int,int,int,int)),wAll,SLOT(axisR(int,int,int,int,int,int)));
            break;
        case 8:
            connect(joys,SIGNAL(axisSet(int,int,int,int,int,int)),rWindow,SLOT(axisSteer(int,int,int,int,int,int)));        
            break;
        default:
            break;

    }

    CurrentValue = A;

}
