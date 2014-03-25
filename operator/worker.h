#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QString>
#include <QSlider>

class Worker : public QObject
{
    Q_OBJECT
private:
    int servoNumber;
    QString send;



public:
    int slideValue;
    QSlider *slidePointer;
    explicit Worker(QObject *parent = 0);
    void Initialize(QSlider *one,int servo);
    int upperValue;
    int lowerValue;
    int endPointLow;
    int endPointHigh;
    int startPoint;
    bool echo;
    int map();
    void sendForce(int microValue);

signals:
    void WorkerToTerminalInternal(QString out);
    void WorkerToSend(QString out);

public slots:
    void keyInput(QString data);
    void SliderRecieved(int value);
    void joyInput(int x0,int x1,int x2,int x3,int x4,int x5);

};

#endif // WORKER_H
