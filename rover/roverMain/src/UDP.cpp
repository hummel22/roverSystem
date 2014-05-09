#include "UDP.h"

UDP::UDP()
{
    //ctor
}

UDP::~UDP()
{
    //dtor
}


void UDP::initialize(char* arg1, char* arg2)
{
    IP = arg1;
    port = atoi(arg2);
    socketIdentifier = socket(AF_INET,SOCK_DGRAM,0);
    cout << "IP address: "<< IP<<endl;
    cout<< "Port Address" <<port<<endl;
    cout << "Socket Returned: "<<socketIdentifier<<endl;

    //Set to Non Blocking - no hangups waiting for recvfrom()
    fcntl(socketIdentifier, F_SETFL, O_NONBLOCK);

    //My Address
    //Bind Socket to Local IP and port 7777
    memset((char *)&myAddr, 0, sizeof(myAddr));
    myAddr.sin_family = AF_INET;
    myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myAddr.sin_port = htons(7777);
    socklen_t addrlen = sizeof(myAddr);
    //checks if bind succesful
    if (bind(socketIdentifier, (struct sockaddr *)&myAddr, sizeof(myAddr)) < 0)
    {
        perror("bind failed");
    }
    //Set socket structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, IP, &(serverAddr.sin_addr));
    const char* start = "Initialize Connection";
    sendto(socketIdentifier,start,strlen(start),0,(struct sockaddr *)&serverAddr,sizeof(serverAddr));

}

void UDP::send(const char* data)
{
sendto(socketIdentifier,data,strlen(data),0,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
}

string UDP::receive()
{
    string fail = "failed";
    recvlen = recvfrom(socketIdentifier, buff, 256, 0, (struct sockaddr *)&myAddr, &addrlen);

    if (recvlen > 0)
    {
        buff[recvlen] = 0;

        //Typecast char to QString and send Signal
        string str = (string)buff;
        return str;
    } else{return fail; }
}

