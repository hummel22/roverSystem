#include "hradiobutton.h"

HRadioButton::HRadioButton(QWidget *parent) :
    QRadioButton(parent)
{
    ButtonIdentifier=0;
    QObject::connect(this,SIGNAL(toggled(bool)),this,SLOT(toggledOn(bool)));
}

void HRadioButton::initialize(int identifier)
{
    ButtonIdentifier = identifier;
}

void HRadioButton::toggledOn(bool onOff)
{
    if(this->isChecked())
    {
        emit clicked(ButtonIdentifier);
        emit RadioButtontoTerminalInternal((QString)"RADIO: RadioButton "+QString::number(ButtonIdentifier)+(QString)" is on");
    }
}

