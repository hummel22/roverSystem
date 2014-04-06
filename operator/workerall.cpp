#include "workerall.h"

ArmController::ArmController(QObject *parent) :
    QObject(parent)
{
}

void ArmController::addWorker(Servo *temp)
{
    //Build list of servos to control
    workerList.append(temp);
}

void ArmController::keyInput(QString data)
{
    //Convert xyz to desired servo angle
}


void ArmController::axisR(int x0, int x1, int x2, int x3, int x4, int x5)
{
    //AdditionalValues
    int Xadd = -x0*3/32175;
    int Shoulder = -x1*3/32175;
    int Zadd = -(x2-x5)*10/32175;
    int Base = -x3*3/32175;
    int Elbow = x4*3/32175;

    //Angle Caluculations
    //fill x[5] with number
    //Test- Filler
    int x[5];
    x[0] = Base;
    x[1] = Shoulder;
    x[2] = Elbow;
    x[3] = 0;
    x[4] = 0;
    x[5] = 0;

    //int NumberOfClawServos = 6    - hard coded at current moment
    for(int i = 0;i < 6; i++)
    {
        if(workerList.at(i)->sliderValue + x[i] > workerList.at(i)->upperBound)
        {
            x[i] = 0;
        }else if(workerList.at(i)->sliderValue + x[i] <  workerList.at(i)->lowerBound)
        {
            x[i] = 0;
        }else if(x[i] != 0)
        {
            workerList.at(i)->sendForce(workerList.at(i)->sliderValue + x[i]);
        }

        //Send Pack Here


    }
}
void ArmController::updateMinMax(int workerNumber, int Upper, int Lower)
{

}

//Resets to 1500 - Used in Beta Testing on reset
void ArmController::reset()
{
    workerList.at(0)->sendForce(1500);
    workerList.at(1)->sendForce(1500);
    workerList.at(2)->sendForce(1500);
}
