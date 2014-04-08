#include "motor.h"

Motor::Motor(QObject *parent) :
    QObject(parent)
{
    UpperLimit = 255;
}


void Motor::UpdateLimit()
{

}
