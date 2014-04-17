#ifndef WORKERROVER_H
#define WORKERROVER_H

#include <QObject>
#include <motor.h>
#include <QList>
#include <worker.h>
#include <qdebug.h>
class RoverController : public QObject
{
    Q_OBJECT
private:
    int turnWheel(Servo *servo, int joystickValue); //return Microseconds / set Slider Angle
    int motorSpeed(Motor, int joystickValue); //return 0-255
    int map(int Value,int upper1,int lower1,int upper2, int lower2); //Convert value to number between 2

    Servo *frontleftSERVO;
    Servo *frontrightSERVO;
    Servo *backleftSERVO;
    Servo *backrightSERVO;
    Servo *panServo;
    Servo *tiltServo;

    Motor *frontleftMOTOR;
    Motor *frontrightMOTOR;
    Motor *middleleftMOTOR;
    Motor *middlerightMOTOR;
    Motor *backleftMOTOR;
    Motor *backrightMOTOR;




public:
    explicit RoverController(QObject *parent = 0);
    void initialize(QList<Motor*>mot,QList<Servo*> serv);


signals:
    void toTerminalInternal(QString out);
    void Send(QString out);
    void powerUpdate(int Power);

public slots:
    void keyInput(QString data);
    void joystickData(int X1,int Y1,int LT,int X2,int Y2,int RT);


};

#endif // WORKERROVER_H
