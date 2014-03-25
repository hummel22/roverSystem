#include "workerall.h"

WorkerAll::WorkerAll(QObject *parent) :
    QObject(parent)
{
}

void WorkerAll::addWorker(Worker *temp)
{
    //Build list of servos to control
    workerList.append(temp);
}

void WorkerAll::keyInput(QString data)
{
    //Apply math here to convert xyz to desired servo angle
}


void WorkerAll::axisR(int x0, int x1, int x2, int x3, int x4, int x5)
{
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
        if(workerList.at(i)->slideValue + x[i] > workerList.at(i)->endPointHigh)
        {
            x[i] = 0;
        }else if(workerList.at(i)->slideValue + x[i] <  workerList.at(i)->endPointLow)
        {
            x[i] = 0;
        }else if(x[i] != 0)
        {
            workerList.at(i)->sendForce(workerList.at(i)->slideValue + x[i]);
        }

        //Send Pack Here


    }
}
void WorkerAll::updateMinMax(int workerNumber, int Upper, int Lower)
{

}

void WorkerAll::reset()
{
    workerList.at(0)->sendForce(1500);
    workerList.at(1)->sendForce(1500);
    workerList.at(2)->sendForce(1500);
}
