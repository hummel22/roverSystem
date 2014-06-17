#include "mythread.h"


myThread::myThread(QObject *parent) :
    QObject(parent)
{
}


void myThread::DoSetup(QThread &cThread)
{
    QObject::connect(&cThread,SIGNAL(started()),this,SLOT(DoWork()));
}

//Main() of New Thread
void myThread::DoWork()
{
    qDebug()<<"THREAD: Thread Created Succesfully: Waiting For First Message";
    emit ThreadtoInternal((QString)"THREAD: Thread Created Succesfully: Waiting For First Message");

    //Wait for Initial Connection
    sock->WaitForData();
    sock->Open = true; //Open Socket for Sending
    qDebug()<<"THREAD: First Message Received";
    emit ThreadtoInternal((QString)"THREAD: First Message Received");


    //Continously Wait for Data
    while(1)
    {
        sock->WaitForData();

    }


}


