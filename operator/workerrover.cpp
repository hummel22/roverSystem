#include "workerrover.h"

WorkerRover::WorkerRover(QObject *parent) :
    QObject(parent)
{
}

void WorkerRover::initialize()
{
    //Set default values
    int motorLimits1[3][4]={ {500,2000,500,2000},
                  {500,2000,500,2000},
                  {500,2000,500,2000}};
    int servoLimits1[2][4]={ {500,2000,500,2000},
                   {500,2000,500,2000}};
    //motorLimits=motorLimits1;
    //servoLimits=servoLimits1;
}

void WorkerRover::keyInput(QString data)
{
    //take input (XY) and send to rover
}

void WorkerRover::updateMotor(int upper[3][4])
{

}
void WorkerRover::axisSteer(int x0, int x1, int x2, int x3, int x4, int x5)
{

}
