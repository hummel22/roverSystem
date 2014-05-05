#ifndef UDP_H
#define UDP_H

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

class UDP{
private:
    char* IP;
    int port;
    char* data;
    int socketIdentifier;
    char buff[256];
    struct sockaddr_in serverAddr;
    struct sockaddr_in myAddr;
    int bindReturn;
    int recvlen;
    socklen_t addrlen;


public:
    UDP();
    ~UDP();
    void initialize(char* arg1, char* arg2);
    void send(const char* data);
    string receive();

};
#endif // UDP_H
