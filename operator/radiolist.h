#ifndef RADIOLIST_H
#define RADIOLIST_H

#include <QObject>
#include <QList>
#include <QSlider>
#include <hradiobutton.h>
#include <worker.h>
#include <keywindoe.h>
#include <joystickinput.h>
#include <workerall.h>
#include <workerrover.h>
#include <roverwindow.h>
#include <udpwork.h>
#include <QTimer>

class linkManager : public QObject
{
    Q_OBJECT
private:
    QList<Servo*> Servos;
    QList<HRadioButton*> RadioButtons;
    keyWindoe *keys;
    void setConfiguration(int A);
    int CurrentValue;
    QTimer * timer;

public:
    explicit linkManager(keyWindoe *key,QObject *parent = 0);
    void addSlide(Servo *switcher);
    void addButton(HRadioButton *rbutton);
    joystickInput *jInput;
    ArmController *Arm;
    RoverController *Drive;
    UDPwork *mySocket;

    roverWindow *rWindow; //Testing purposes


signals:
    void Send(QString send);

public slots:
    void radioReceived(int on);
    void buttonPressed(int x);


};

#endif // RADIOLIST_H
