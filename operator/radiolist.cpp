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
            break;
        case 2:
        if (CurrentValue > 1)
            {
                CurrentValue--;
            } else
            {
                CurrentValue = rButtons.count();
            }
            rButtons.at(CurrentValue-1)->setChecked(true);
            break;


    }
}

void RadioList::setConfiguration(int A)
{
    //Disconnet All Switches
    for(int i = 0;i < switches.count();i++)
    {
        switches.at(i)->slidePointer->setEnabled(false);
        disconnect(keys,SIGNAL(sendKey(QString)),switches.at(i),SLOT(keyInput(QString)));
        disconnect(joys,SIGNAL(axisSet(int,int,int,int,int,int)),switches.at(i),SLOT(joyInput(int,int,int,int,int,int)));
    }
    disconnect(joys,SIGNAL(axisSet(int,int,int,int,int,int)),wAll,SLOT(axisR(int,int,int,int,int,int)));
    disconnect(joys,SIGNAL(axisSet(int,int,int,int,int,int)),rWindow,SLOT(axisSteer(int,int,int,int,int,int)));

    //Make New Connection
    if(A < switches.count())        //Single Servo Connection
    {
        switches.at(A)->slidePointer->setEnabled(true);
        connect(keys,SIGNAL(sendKey(QString)),switches.at(A),SLOT(keyInput(QString)));
        connect(joys,SIGNAL(axisSet(int,int,int,int,int,int)),switches.at(A),SLOT(joyInput(int,int,int,int,int,int)));

    } else if(A == switches.count())    //Arm Control
    {
        connect(joys,SIGNAL(axisSet(int,int,int,int,int,int)),wAll,SLOT(axisR(int,int,int,int,int,int)));

    } else if(A == switches.count() + 1)    //Rover Control
    {
        connect(joys,SIGNAL(axisSet(int,int,int,int,int,int)),rWindow,SLOT(axisSteer(int,int,int,int,int,int)));
    }

    CurrentValue = A + 1;

}
