#include "joythread.h"

joyThread::joyThread(QObject *parent) :
    QObject(parent)
{
}

void joyThread::DoSetup(QThread &cThread)
{
    QObject::connect(&cThread,SIGNAL(started()),this,SLOT(DoWork()));
}

void joyThread::DoWork()
{
    qDebug()<<"In thread Befre init";
    jInputs->Initialize();
    qDebug()<<"After Init";
    while(1)
    {
        jInputs->getInput();
        usleep(2000);
    }

}
