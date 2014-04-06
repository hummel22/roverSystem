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

class RadioList : public QObject
{
    Q_OBJECT
private:
    QList<Servo*> Servos;
    QList<HRadioButton*> RadioButtons;
    keyWindoe *keys;
    void setConfiguration(int A);
    int CurrentValue;

public:
    explicit RadioList(keyWindoe *key,QObject *parent = 0);
    void addslide(Servo *switcher);
    void addButton(HRadioButton *rbutton);
    joystickInput *jInput;
    ArmController *Arm;
    RoverController *Drive;
    roverWindow *rWindow;


signals:
    void toSend(QString send);

public slots:
    void RadioReceive(int on);
    void buttons(int x);


};

#endif // RADIOLIST_H
