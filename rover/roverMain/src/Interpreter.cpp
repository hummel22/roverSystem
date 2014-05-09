#include "Interpreter.h"

Interpreter::Interpreter()
{
    //ctor
}

Interpreter::~Interpreter()
{
    //dtor
}



void Interpreter::initialize(Arduino serialObject,UDP socketObject){
    serial = serialObject;
    socks = socketObject;
    POWER_ON = 400;
    POWER_OFF = 1200;

    currentHeader = 0;
    timeInterval = POWER_OFF;
    pingInterval = 8000;
    clock_gettime(CLOCK_REALTIME,&getTime);
    lastTime = (getTime.tv_nsec/1000000)+getTime.tv_sec*1000;
    shutdown =new int[12]{0,41,1500,1500,1500,1500,1500,1500,0};
    shutdownSent = false;


}

//Switch Statement for sorting commands
void Interpreter::interpret(const char* data){

    //get time of data
    clock_gettime(CLOCK_REALTIME,&getTime);
    thisTime = (getTime.tv_nsec/1000000)+getTime.tv_sec*1000;

    //split command in interger array
    char* c = (char*)data;  //typecaset const to  variable
    char*ch = strtok(c,"/");    //delimninate to "/"
    int x[12];
    int i = 0;
    //for loop convert all chars to ints
    while(ch != NULL)
    {
        x[i] = atoi(ch);
        i++;
        ch = strtok(NULL,"/");

    }


    //falied to receive is below 0. creates counter for number of fails in a ro
    if (x[0] < 0)
    {
        if(thisTime-lastTime > pingInterval)
        {
            cout << "Shutdown Reached"<<endl;
            socks.send("4/Ping");
            cout << "Ping sent"<<endl;
        }
        if ((thisTime-lastTime > timeInterval)  && (!shutdownSent))
        {

            pass(shutdown,true);
            shutdownSent = true;
            timeInterval = POWER_OFF;
            usleep(8000);
            pass(shutdown,true);


        }
    } else      //data was found reset counter
    {
        lastTime = thisTime;
        shutdownSent = false;
    }








    //SWitch command
    //Commands 1-8 are single servo operation
    //Case 22 is when nothing is received from operator (Probably change to negative interger and before loop
    //if(headercheck(x[0]))   //make sure commands are in order
    if(true)
    {
        //cout << "ID: " << x[1] <<endl;
        switch(x[1]){

            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:

                servoSet(x[1],x[2]);
                break;
            case 21:
                //Check Arduino Connection
                // This should be done using arduino.h functions that return strings

                //Check if connection is open
                //bool check = serial.check();


                //Loop to try and reconnect(attempt 5 times
                //int count = 0;
                //while(!check && count < 5)
                //{ check = serial.reconnect(); count++;}

                //If connection is good send serial values
                //if(check)
                //{
                //Retrn values of connection
                //string SerialValues = serial.Info()
                //socket.send(string);
                //} else { socket.send("There is no Connection"}
                break;

            case 22:
                //checked for commands from operator
                cout << "Ping Answered Succesfully" << endl;
                break;
            case 23:
                //Switch Protocols
                //socket.protocol(x[2]_;
            case 25:
                //Reset Arduino
                //serial.reconnect();
                //break;
            case 26:
                //Force Header Synce
                //currentHeader = x[1];
                //break;
            case 27:
                //Set New Shutdoen limit
                //shutdonw = x[1];
                //break;
            case 30:
                //Force Servo Sync
                //pass(x);
                //break;
            case 31:
                //Set Upper/lower Boundary Limits
                ////pass(x);
                //break;
            case 32:
                //Set Filter
                //pass(x);
                //break;
            case 33:
                //Requeste Servo Limits:
                //pass(x):
                //break;

                //shoudl return Upper/loower limits/ current value/ / filter valued
            case 34:
                //Set Loop Delay
                //pass(x);
                //break;

            case 35:
                //Set motor max value
                //pass(x);
                //break;
            case 40:
                //Pass Arm Control to Rover
                pass(x);
                break;
            case 41:
                //Steering Control
                if(x[7]!=0)
                {
                    timeInterval = POWER_ON;
                } else{timeInterval = POWER_OFF;}
                pass(x,true);
                break;
            default:
                break;


        }
    }
}

//check header to insure proper order
//send reset command once header reaches over 500
//return false if header out of order
bool Interpreter::headercheck(int num)
{

    return true;
}

//set servo angle
void Interpreter::servoSet(int servo,int angle)
{
    std::ostringstream oss;
    oss << servo << "/" << angle << "/";
    serial.send(oss.str());

}


//pass al values except header to arduino
void Interpreter::pass(int x[12])
{
    //get data length
    int len = sizeof(x);
    //Build string
    std::ostringstream oss;
    for (int i = 1;i<=len-1;i++)
    {
        oss<< x[i] << "/" ;
    }
    //send string to arduino
    cout << "Passing: " << oss.str() << endl;
    serial.send(oss.str());
}


//IDK
void Interpreter::pass(int x[12],bool)
{
    //get data length
    int len = sizeof(x);
    std::ostringstream oss;
    for (int i = 1;i<=len;i++)
    {
        oss<< x[i] << "/" ;
    }
    cout << "Passing: " << oss.str() << endl;
    serial.send(oss.str());

    //Build string

    //send string to arduino
}
