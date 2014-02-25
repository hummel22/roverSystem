#include "udpwork.h"


UDPwork::UDPwork(QWidget *parent) :
    QWidget(parent)
{
    Open = false;
}

//FUNCTION - Initializes Server  and opens socket for listening
void UDPwork::InitializeConnection()
{
    header = 0;
    //Create Socket
    emit UDPtoTerminalInternal((QString)"UDP INIT: Creating Socket");
    socklen_t addrlen = sizeof(remaddr);
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("cannot create socket\n");
        emit UDPtoTerminalInternal((QString)"UDP INIT: Failed to Create Socket");

    } else {

        //Bind Socket to Local IP and port 1153
        memset((char *)&myaddr, 0, sizeof(myaddr));
        myaddr.sin_family = AF_INET;
        myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        myaddr.sin_port = htons(1153);
        emit UDPtoTerminalInternal((QString)"UDP INIT: Socket Succesfully Opened");
        //check if bind succesful
        emit UDPtoTerminalInternal((QString)"UDP INIT: Attempting to Bind Socket");
        if (bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0)
        {
            perror("bind failed");
            emit UDPtoTerminalInternal((QString)"UDP INIT: Bind Failed");

        }else{
            emit UDPtoTerminalInternal((QString)"UDP INIT: Bind Succesfull");
        }


    }

}


//FUNCTION - Waits for data on given port
QString UDPwork::WaitForData()
{
    emit UDPtoTerminalInternal((QString)"UDP WAIT: waiting on Port 1153");
    recvlen = recvfrom(fd, buf, 256, 0, (struct sockaddr *)&remaddr, &addrlen);

    if (recvlen > 0)
    {
        buf[recvlen] = 0;
        emit UDPtoTerminalInternal((QString)"UDP WAIT: Bytes Recieved");

        //Typecast char to QString and send Signal
        QString str = (QString)buf;
        emit Received(str);
        return str;
    }
}


//SLOT - Send UDP Message
void UDPwork::Send(QString send)
{
    //Check to see if sock has been created
    if (Open)
    {
        send = QString::number(header) +"/"+ send;
        header=header+1;
        const char* test =send.toStdString().c_str();
        sendto(fd,test,strlen(test),0,(struct sockaddr *)&remaddr,sizeof(remaddr));
        emit UDPtoTerminalSend(send);


    } else {
        emit UDPtoTerminalSend((QString)"UDP SEND: No Client To Send Data To");
    }

}

//SLOT - Send UDP Message
void UDPwork::SendTest()
{
    //Check to see if sock has been created
    if (Open)
    {
        const char* test = "Initialize Connection";
        sendto(fd,test,strlen(test),0,(struct sockaddr *)&remaddr,sizeof(remaddr));
        qDebug()<<"UDP SEND: Sent Message";

    } else {
        qDebug()<<"UDP SEND: Not Client To Send Data To";
    }

}

void UDPwork::resetHeader()
{
    header = 0;
}
