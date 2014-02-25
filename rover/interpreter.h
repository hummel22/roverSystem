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
    char* c = (char*)data;
    char*ch = strtok(c,"/");
    int x[8];
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
        switch(x[1]){
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                servoSet(x[1],x[2]);
                break;
            case 22:
                //checked for commands from operator
                cout << "Ping Answered Succesfully" << endl;
                break;
            case 35:
                //force servo sync
                cout << "Force Servo Sync" << endl;
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


#endif
