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
    int Yadd = -x1*3/32175;
    int Zadd = -(x2-x5)*3/32175;
    int Clawadd = -x3*3/32175;
    int ClawSpinadd = -x4*3/32175;

    //Angle Caluculations
    //fill x[5] with number
    //Test- Filler
    int x[5];
    x[0] = Yadd;
    x[1] = -Xadd;
    x[2] = Yadd- Xadd;
    x[3] = Clawadd;
    x[4] = ClawSpinadd;
    x[5] = Xadd + Clawadd;


    for(int i = 0;i < workerList.count();i++)
    {
        if(workerList.at(i)->slideValue + x[i] > 175)
        {
            x[i] = 0;
        }else if(workerList.at(i)->slideValue + x[i] < 0)
        {
            x[i] = 0;
        }
        workerList.at(i)->slideValue = workerList.at(i)->slideValue + x[i];
        workerList.at(i)->slidePointer->setValue(workerList.at(i)->slideValue);
    }
}
