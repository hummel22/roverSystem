#ifndef ARDUINO_H
#define ARDUINO_H



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

};



Arduino::Arduino(){}
Arduino::~Arduino(){}

void Arduino::initialize(){
    //###Cycle Though to search ports for (In case arduin Switches ports) #####

    int portNumber = 0;
    bool loop = true;
	char* portId = "/dev/ttyACM";  //adjust for specific port

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
        }
        portNumber++;
    }
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




#endif
