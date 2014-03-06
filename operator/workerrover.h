#ifndef WORKERROVER_H
#define WORKERROVER_H

#include <QObject>

class WorkerRover : public QObject
{
    Q_OBJECT
private:
    //Upper and lower limits. * no need to hold value alwasy taken from controller
    int motorLimits[3][4];
    int servoLimits[2][4];


public:
    explicit WorkerRover(QObject *parent = 0);
    void initialize();

signals:
    void WorkerRoverToTerminalInternal(QString out);
    void WorkerRoverToSend(QString out);
    void UpdateGUI(int x0,int x1,int x2,int x3,int x4,int x5);

public slots:
    void keyInput(QString data);
    void updateMotor(int limits[3][4]);
    void axisSteer(int x0,int x1,int x2,int x3,int x4,int x5);
};

#endif // WORKERROVER_H
