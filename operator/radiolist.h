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
    QList<Worker*> switches;
    QList<HRadioButton*> rButtons;
    keyWindoe *keys;
    void setConfiguration(int A);
    int CurrentValue;

public:
    explicit RadioList(keyWindoe *key,QObject *parent = 0);
    void addslide(Worker *switcher);
    void addButton(HRadioButton *rbutton);
    joystickInput *joys;
    WorkerAll *wAll;
    WorkerRover *wRover;
    roverWindow *rWindow;


signals:
    void toSend(QString send);

public slots:
    void RadioReceive(int on);
    void forcesync();
    void axisSet(int x0,int x1,int x2,int x3,int x4,int x5);
    void buttons(int x);


};

#endif // RADIOLIST_H
