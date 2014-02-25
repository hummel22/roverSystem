#ifndef JOYTHREAD_H
#define JOYTHREAD_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <joystickinput.h>
#include <QString>
class joyThread : public QObject
{
    Q_OBJECT
public:
    explicit joyThread(QObject *parent = 0);
    void DoSetup(QThread &cThread);
    joystickInput *jInputs;

signals:
    void toInternal(QString send);

public slots:
    void DoWork();

};

#endif // JOYTHREAD_H
