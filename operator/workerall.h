#ifndef WORKERALL_H
#define WORKERALL_H

#include <QObject>
#include <worker.h>
#include <QList>
#include <qdebug.h>
#include <QApplication>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPlainTextEdit>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <qmath.h>

class ArmController : public QObject
{
    Q_OBJECT
private:
    QList<Servo*> servoList;
    QString dataSent;
    int DeadZone;
    int count;
    int X1_DEADZONE;
    int Y1_DEADZONE;
    int X2_DEADZONE;
    int Y2_DEADZONE;
    int deadzoneCheck(int value,int deadzone);
    int boundCheck(int a, Servo* servo);

    //Arm Postions
    //Drive
    int BASE_DRIVE_POSTION;
    int SHOULDER_DRIVE_POSTION;
    int ELBOW_DRIVE_POSTION;
    int WRIST_DRIVE_POSTION;
    int WRIST_ROTATE_DRIVE_POSTION;

    //Ready
    int BASE_READY_POSTION;
    int SHOULDER_READY_POSTION;
    int ELBOW_READY_POSTION;
    int WRIST_READY_POSTION;
    int WRIST_ROTATE_READY_POSTION;
    void toReady();

   
public:
    explicit ArmController(QObject *parent = 0);
    void addWorker(Servo *temp);
    

signals:
    void toTerminalInternal(QString out);
    void Send(QString out);


public slots:
    void keyInput(QString data);
    void joystickData(int X1,int Y1,int LT,int X2,int Y2,int RT);
    void reset();
    void timeCheck();
    void buttonPressed(int a);
    void readyToDrive();
    void driveToReady();
    void toBin();
    void storageToReady();
};

#endif // WORKERALL_H
