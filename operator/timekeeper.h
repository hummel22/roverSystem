#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

#include <QObject>
#include <QTimer>
#include <qdebug.h>
class TimeKeeper : public QObject
{
    Q_OBJECT
private:
    QTimer * timer;
    int N; //interval betwen time milliseconds

public:
    explicit TimeKeeper(QObject *parent = 0);
    void setTimer();

signals:
    void timeCheck();

public slots:
    void setInterval(int N);
    void timerOff();

};

#endif // TIMEKEEPER_H
