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
    emit toTerminalInternal((QString)"UDP INIT: Creating Socket");
    socklen_t addrlen = sizeof(remaddr);
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("cannot create socket\n");
        emit toTerminalInternal((QString)"UDP INIT: Failed to Create Socket");

    } else {

        //Bind Socket to Local IP and port 1153
        memset((char *)&myaddr, 0, sizeof(myaddr));
        myaddr.sin_family = AF_INET;
        myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        myaddr.sin_port = htons(1153);
        emit toTerminalInternal((QString)"UDP INIT: Socket Succesfully Opened");
        //check if bind succesful
        emit toTerminalInternal((QString)"UDP INIT: Attempting to Bind Socket");
        if (bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0)
        {
            perror("bind failed");
            emit toTerminalInternal((QString)"UDP INIT: Bind Failed");

        }else{
            emit toTerminalInternal((QString)"UDP INIT: Bind Succesfull");
        }


    }

}


//FUNCTION - Waits for data on given port
QString UDPwork::WaitForData()
{
    emit toTerminalInternal((QString)"UDP WAIT: waiting on Port 1153");
    recvlen = recvfrom(fd, buf, 256, 0, (struct sockaddr *)&remaddr, &addrlen);

    if (recvlen > 0)
    {
        buf[recvlen] = 0;
        emit toTerminalInternal((QString)"UDP WAIT: Bytes Recieved");

        //Typecast char to QString and send Signal
        QString str = (QString)buf;
        emit Received(str);
        return str;
    }
}


//SLOT - Send UDP Message
void UDPwork::Send(QString send)
{
    send = QString::number(header) +"/"+ send;      //Attach header
    header=header+1;                                //Increase Header Size
    const char* test =send.toStdString().c_str();   //Convert to const char*
    //Check to see if sock has been created
    if (Open)
    {  
        sendto(fd,test,strlen(test),0,(struct sockaddr *)&remaddr,sizeof(remaddr));     //Send
        emit toTerminalSend(send);


    } else {
        emit toTerminalSend("UDP SEND: " + send);
        emit toTerminalSend((QString)"UDP SEND: No Client To Send Data To");
    }

}


void UDPwork::resetHeader()
{
    header = 0;
}
