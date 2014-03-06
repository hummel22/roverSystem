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

    //Build class objects
    UDP socks;
    Arduino serial;
    Interpreter inter;


    //####Add FFmpeg videoStream Class####//

    //Create Connection with arduino
    serial.initialize();

    //Create Connection with operator//
    socks.initialize("127.0.0.1","1153");

    inter.initialize(serial,socks);

    //####Initialize Video Stream Here##//

    //Wait for arduino to power on//
    usleep(3000000);
    cout << "Start" <<endl;

    const char* test= "test";
    socks.send(test);

    string sendArduino;
    string sendOperator;
    string toInterpreter;

    //loop forever
    while(true){

        usleep(10000);

        //Command From rover//
        sendOperator = serial.receive();
        // Check if command was received
        if (sendOperator.length() > 0)
        {
            //If comand received send to Operator
            socks.send(sendOperator.c_str());
            cout << sendOperator << endl;   //Display to terminal TESTING PURPOSES
        }

        //check for commands from operator
        toInterpreter = socks.receive();
        //cout <<"Socks:Receive: " << toInterpreter << endl;
         //TESTING PURPOSE
        //Pass command to Interpreter


        if (toInterpreter.compare((string)"failed") == 0)
        {
            toInterpreter = "-10";
        } else{
             cout <<"Recieved Operator: "<< toInterpreter<<endl;
        }

        inter.interpret(toInterpreter.c_str());


    }


}
