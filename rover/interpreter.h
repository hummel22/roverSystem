#ifndef INTERPRETER_H
#define INTERPRETER_H



class Interpreter {

private:
    //Current Servo Values
    int Arm;
    int Shoulder;
    int Elbow;
    int Wrist;
    int Claw;
    int ShoulderRotate;
    int WristRotate;
    bool headercheck(int num);
    void servoSet(int servo,int angle);
    void pass(int x[8]);


    Arduino serial;
    UDP socks;

    //Counters
    int shutdownCounter; //counter for messages not received
    int shutdownMax;  //Timeout for not receiveing commands
    int currentHeader;
    bool check;




public:
    void interpret(const char* data);
    void initialize(Arduino temp,UDP temp2 );



};


void Interpreter::initialize(Arduino temp,UDP temp2){
    serial = temp;
    socks = temp2;
    shutdownMax =1000;
    shutdownCounter=0;
    currentHeader = 0;


}

//Switch Statement for sorting commands
void Interpreter::interpret(const char* data){

    //split command in interger array
    char* c = (char*)data;  //typecaset const to  variable
    char*ch = strtok(c,"/");    //delimninate bt "/"
    int x[20];
    int i = 0;
    while(ch != NULL)
    {
        x[i] = atoi(ch);
        i++;
        ch =  strtok(NULL,"/");
    }


    //falied to receive is below 0. creates counter for number of fails in a ro
    if (x[0] < 0)
    {
        shutdownCounter++;
        if(shutdownCounter > shutdownMax)
        {
            cout << "Shutdown Reached"<<endl;
            socks.send("Ping");
            cout << "Ping sent"<<endl;
        }
    } else
    {
        shutdownCounter = 0;
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
                cout << "Switch Set Servo" << endl;
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
                //pass(x[8]);
                //break(x);
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
    bool go = false;
    bool allowReset = false;

    if(num >= 500)
    {
        //send Header reset command
        socks.send("34");
        allowReset = true;
    }

    if((num > currentHeader))
    {
        go =true;
        currentHeader = num;
    } else if (allowReset)
    {
        go =true;
        currentHeader = num;
    }
    //return go;
    return true;
}

//set servo angle
void Interpreter::servoSet(int servo,int angle)
{
//    string command = "";
//    cout << "Setting Servo: "<< servo << endl;
//    command.append(boost::lexical_cast<std::string>(servo);
//    command.append("/");
//    command.append((char)(angle));
//    command.append("/");

    std::ostringstream oss;
    oss << servo << "/" << angle << "/";
    cout<<"Made command "<< oss.str() << endl;
    serial.send(oss.str());

}

void Interpreter::pass(int x[20])
{
    //get data length
    int len = sizeof(x);
    std::ostringstream oss;
    for (int i = 1;i<=len-1;i++)
    {
        oss<< x[i] << "/" ;
    }
    cout << "Passing to Arduino: " << oss.str();
    serial.send(oss.str());

    //Build string

    //send string to arduino
}


#endif
