#ifndef JOYSTICKINPUT_H
#define JOYSTICKINPUT_H

#include <QObject>
#include <QCoreApplication>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <linux/joystick.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "fcntl.h"
#include "termios.h"
#include "sstream"
#include <qdebug.h>


class joystickInput : public QObject
{
    Q_OBJECT
private:
    struct js_event event;
    struct joystick_state *state;
    bool on;
    int fd; //file descriptor
    int x[6];
    int b;
    bool buttonReleased;
    int spacer;
public:
    explicit joystickInput(QObject *parent = 0);
    void Initialize();
    void getInput();

signals:
    void axisSet(int x0,int x1,int x2,int x3,int x4,int x5);
    void buttons(int b);
    void toInternal(QString send);

public slots:


};

#endif // JOYSTICKINPUT_H
