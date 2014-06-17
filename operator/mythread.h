#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include "udpwork.h"



class myThread : public QObject
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = 0);

    //VARIABLES
    UDPwork *sock;

    //FUNCTIONS
    void DoSetup(QThread &cThread);

signals:
    void ThreadtoInternal(QString memo);
public slots:
    void DoWork();

};

#endif // MYTHREAD_H
