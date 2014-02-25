#include "keywindoe.h"
#include <QKeyEvent>

keyWindoe::keyWindoe(QWidget *parent) :
    QWidget(parent)
{
}

void keyWindoe::keyPressEvent(QKeyEvent *e)
{
    emit sendKey(e->text());
}
