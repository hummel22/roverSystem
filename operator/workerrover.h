#ifndef WORKERROVER_H
#define WORKERROVER_H

#include <QObject>

class WorkerRover : public QObject
{
    Q_OBJECT
private:
    //Upper and lower limits. * no need to hold value alwasy taken from controller
    int motorUpper[3][2];
    int motorLower[3][2];
    int servoUpper[2][2];
    int servoLower[2][2];


public:
    explicit WorkerRover(QObject *parent = 0);
    void initialize();

signals:
    void WorkerRoverToTerminalInternal(QString out);
    void WorkerRoverToSend(QString out);

public slots:
    void keyInput(QString data);
    void updateMotor(int upper[3][2],int lower[3][2]);
};

#endif // WORKERROVER_H
