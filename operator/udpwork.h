#ifndef UDPWORK_H
#define UDPWORK_H

#include <QWidget>
#include <QString>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <QDebug>
#include <QSocketNotifier>
#include <QObject>


class UDPwork : public QWidget
{
    Q_OBJECT
private:
    int header;
    struct sockaddr_in myaddr;      /* our address */
    struct sockaddr_in remaddr;      /* remote address */
    socklen_t addrlen;               //addres length
    int recvlen;                    /* # bytes received */
    int fd;                         /* our socket */
    char buf[256];/* receive buffer */

public:
    explicit UDPwork(QWidget *parent = 0);

    //VARIABLES
    bool Open; //Bool to show open
    QString WaitForData(); //Return String Received

    //FUNCTIONS
    void InitializeConnection();   


signals:
    void toTerminalInternal(QString in);
    void toTerminalSend(QString dat);
    void Received(QString send);                //received string from client

public slots:
    void Send(QString send);    //Send UDP - Pass Qstring
    void resetHeader();         //Set header to 0



};

#endif // UDPWORK_H
