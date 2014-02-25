#include "hradiobutton.h"

HRadioButton::HRadioButton(int num,QWidget *parent) :
    QRadioButton(parent)
{
    ButtonIdentifier=num;
    QObject::connect(this,SIGNAL(toggled(bool)),this,SLOT(toggledOn(bool)));
}


void HRadioButton::toggledOn(bool onOff)
{
    if(this->isChecked())
    {
        emit clicked(ButtonIdentifier);
        emit RadioButtontoTerminalInternal((QString)"RADIO: RadioButton "+QString::number(ButtonIdentifier)+(QString)" is on");
    }
}

