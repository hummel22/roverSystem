#include "workerrover.h"

WorkerRover::WorkerRover(QObject *parent) :
    QObject(parent)
{
}

void WorkerRover::initialize()
{
    //Set default values
}

void WorkerRover::keyInput(QString data)
{
    //take input (XY) and send to rover
}

void WorkerRover::updateMotor(int upper[3][2], int lower[3][2])
{

}
