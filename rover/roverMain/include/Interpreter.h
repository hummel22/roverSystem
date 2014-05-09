#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include "fcntl.h"
#include "termios.h"
#include <sstream>
#include <sys/time.h>
using namespace std;
#include "UDP.h"
#include "Arduino.h"


class Interpreter {

private:
    //Current Servo Values
    int Arm;
    int Shoulder;
    int Elbow;
    int Wrist;
    int Claw;
    int ShoulderRotate;
    int WristRotate;
    bool headercheck(int num);
    void servoSet(int servo,int angle);
    bool shutdownSent;
    void pass(int x[12]);
    void pass(int x[12],bool);
    int POWER_ON;
    int POWER_OFF;



    Arduino serial;
    UDP socks;

    //Counters
    int currentHeader;
    bool check;
    long long lastTime;
    long long thisTime;
    struct timespec getTime;
    int timeInterval;
    int pingInterval;
    int *shutdown;
    int last[12];
    int repeatCounter;




public:
    Interpreter();
    virtual ~Interpreter();
    void interpret(const char* data);
    void initialize(Arduino temp,UDP temp2 );




};

#endif // INTERPRETER_H
