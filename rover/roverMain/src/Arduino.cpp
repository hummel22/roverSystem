#include "Arduino.h"

Arduino::Arduino()
{
    //ctor
}

Arduino::~Arduino()
{
    //dtor
}


void Arduino::initialize(){
    //###Cycle Though to search ports for (In case arduin Switches ports) #####

    int portNumber = 0;
    bool loop = true;
	char* portId = "/dev/ttyACM";  //adjust for specific port
	struct termios options;

	while(loop){
	    string str;
	    stringstream ss;
        ss << portId << portNumber;
        str = ss.str();

        portName = new char[str.size() + 1];
        std::copy(str.begin(), str.end(), portName);
        portName[str.size()] = '\0'; // don't forget the terminating 0

        cout << "Port set to:  "<< portName<< endl;

        //Open port and set to READ/WRTITE and NONBLOCKING
        serialPort = open(portName, O_RDWR | O_NOCTTY | O_NDELAY );
        cout << "Port Value: " << serialPort << endl;   // resets arduino

        //check if serila port open
        if (serialPort < 0){
            perror ("Error Opening Port");
            if(portNumber<25){loop =true;}else{loop = false;}     //Loop 25 times until found
        }
        else{
            cout <<"Port Successfully Opened; Returned Value: "<< serialPort<<endl;
            loop = false;
            tcgetattr(serialPort, &options);        //get current port options
            cfsetispeed(&options, B115200);
            cfsetospeed(&options, B115200);
            options.c_cflag &= ~PARENB;
            options.c_cflag &= ~CSTOPB;
            options.c_cflag &= ~CSIZE;
            options.c_cflag |= CS8;
            options.c_lflag |= ICANON;
            tcsetattr(serialPort,TCSANOW, &options);

        }
        portNumber++;
    }
    cout << "3" <<endl;
    usleep(1000000);
    cout << "2" <<endl;
    usleep(1000000);
    cout << "1" <<endl;
    usleep(1000000);
    cout << "0" <<endl;
}


string Arduino::receive(){
    char buf[100];       //Create Buffer
    memset(buf,0,sizeof buf);  //Resetts buffer to zero

    //read everything that is cuurently in buffer
    int returns = read(serialPort,buf,sizeof buf);

    if(returns>0){ //if value recieved  couts and delays
        return string(buf); //converts to string to pass bacl
    } else {
        return buf;
    }


}

void Arduino::send(string command)
{
    command = "*"+command;
    //send command
    int check = write(serialPort, command.c_str(),command.length());

    //Check if command Succesful
    if(check>=0)
    {
        cout <<"Sent "<< command<<" to Arduino"<<endl;
    }else{
        cout<<"Write Value = "<< check<<endl;
    }
}


void Arduino::reset()
{
    close(serialPort);
    initialize();
}

void Arduino::flush()
{
    string comp = "x";
    string sendstring = "*/";
    while(receive().compare(comp))
          {
              Arduino::send(sendstring);
          }
    send(sendstring);
}



