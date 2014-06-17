#ifndef ARDUINO_H
#define ARDUINO_H

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

class Arduino{
private:
    char* portName;
    int serialPort;
    int Test;


public:
    Arduino();
    ~Arduino();
    void initialize();
    void send(string command);
    string receive();
    void reset();
    void flush();

};


#endif // ARDUINO_H
