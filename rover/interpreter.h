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
    char* c = (char*)data;      //Change from constant Char*
    char*ch = strtok(c,"/");    //Split data by '/' "
    int x[8];

    //Convert data int integers
    int i = 0;
    while(ch != NULL)
    {
        x[i] = atoi(ch);
        i++;
        ch =  strtok(NULL,"/");
    }

    //TIMEOUT
    //x[0] is the Header - if failed to recieve anything should be -10
    //Will continously count number of recieve failures ina row
    //if exceeds MAX sends ping until data is recieved and resets counter
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
        shutdownCounter = 0;    //reset counter
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
                cout << "Switch Set Servo" << endl;
                servoSet(x[1],x[2]);
                break;
            case 20:
                //Computer System [Timeout Count /  Header Count / Check Arduino Link]
            case 22:
                //checked for commands from operator
                cout << "Ping Answered Succesfully" << endl;
                break;
            case 23:
                //set Pin refresh Rate
            case 30:
                //Arduino System [Check Values - ?]
            case 35:
                //force servo sync
                cout << "Force Servo Sync" << endl;
                break;
            case 40:
                //Servo Settings [Limits / Filters]
            case 50:
                //motor Details
            case 60:
                //Sensor Details
            case 70:
                //Video Details [Change Video - BitRate ]



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

    //Build String to send to Arduino
    std::ostringstream oss;
    oss << servo << "/" << angle << "/";
    cout<<"Made command "<< oss.str() << endl;

    //Send Built String
    serial.send(oss.str());

}


#endif
