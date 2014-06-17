#include "timekeeper.h"

TimeKeeper::TimeKeeper(QObject *parent) :
    QObject(parent)
{
    N = 850;
}


void TimeKeeper::setInterval(int N)
{
    this->N = N;
    //kill clock
    timer->stop();
    //create new clock
    setTimer();
}


void TimeKeeper::setTimer()
{
    //create clock
    timer = new QTimer(0);
    //connect clock to timer Off
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(timerOff()));
    //set timout
    timer->start(N);
}

void TimeKeeper::timerOff()
{
    //emitted to current mode operation
    qDebug()<<"emitted";
    emit timeCheck();

}


