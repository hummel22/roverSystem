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
#include "unistd.h"
#include "fcntl.h"
#include "termios.h"
#include "sstream"
#include "iostream"
#include "string.h"
#include "unistd.h"
#include "fcntl.h"
#include "termios.h"
#include "stdio.h"
#include "sstream"
#include <sstream>



using namespace std;

#include "UDP.h"
#include "Arduino.h"
#include "interpreter.h"



main(){
    string sendArduino;
    string sendOperator;
    string toInterpreter;
    int refreshRate = 10000;

    //Build class objects
    UDP socks;
    Arduino serial;
    Interpreter inter;
    //####Add FFmpeg videoStream Class####//


    //INITIALIZE
    //Create Connection with arduino
    serial.initialize();
    //Create Connection with operator//
    socks.initialize("127.0.0.1","1153");
    //Add sending and receieving to Interpreter
    inter.initialize(serial,socks);
    //####Initialize Video Stream Here##//


    //Wait for arduino to power on//
    usleep(3000000);
    cout << "Start" <<endl;
    //Initiate Second Test After Arduino Load
    const char* test= "test";
    socks.send(test);


    //loop forever
    while(true){

        usleep(refreshRate);

        //ARDUINO IN
        sendOperator = serial.receive();
        // Check if command was received
        if (sendOperator.length() > 0)
        {
            //If comand received from Arduino send to Operator
            socks.send(sendOperator.c_str());
            cout << sendOperator << endl;   //Display to terminal TESTING PURPOSES
        }

        //OPERATOR IN
        toInterpreter = socks.receive();
        //Check if receieved
        if (toInterpreter.compare((string)"failed") == 0)
        {
            toInterpreter = "-10";
        } else{
             cout <<"Recieved Operator: "<< toInterpreter<<endl;
        }
        //Pass to interpreter
        inter.interpret(toInterpreter.c_str());
    }


}
