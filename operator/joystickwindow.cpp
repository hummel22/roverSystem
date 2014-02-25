#include "joystickwindow.h"

joystickWindow::joystickWindow(QObject *parent) :
    QObject(parent)
{

}

void joystickWindow::initialize()
{
    ButtonTerminal = new QPlainTextEdit;
    ButtonTerminal->setMinimumHeight(300);
    ButtonTerminal->setMinimumWidth(100);
    scene = new QGraphicsScene(0,0,1000,300,&m);
    scene->setBackgroundBrush(QColor(51,102,153));
    m.setScene(scene);
    scene->addEllipse(310,50,200,200);
    scene->addEllipse(550,50,200,200);
    scene->addLine(410,20,410,280);
    scene->addLine(650,20,650,280);
    scene->addRect(775,50,35,200);
    scene->addRect(845,50,35,200);
    scene->addWidget(ButtonTerminal);
    X1 = new QGraphicsLineItem;
    Y1 = new QGraphicsLineItem;
    X2 = new QGraphicsLineItem;
    Y2 = new QGraphicsLineItem;
    X1->setLine(400,150,420,150);
    X2->setLine(640,150,660,150);
    Y1->setLine(410,140,410,160);
    Y2->setLine(650,140,650,160);
    X1->setPen(QPen(Qt::yellow));
    Y1->setPen(QPen(Qt::yellow));
    X2->setPen(QPen(Qt::yellow));
    Y2->setPen(QPen(Qt::yellow));

    L1 = new QGraphicsLineItem;
    R1 = new QGraphicsLineItem;
    L1->setLine(775,250,810,250);
    R1->setLine(845,250,880,250);
    L1->setPen(QPen(Qt::red));
    R1->setPen(QPen(Qt::red));
    scene->addItem(X1);
    scene->addItem(X2);
    scene->addItem(Y1);
    scene->addItem(Y2);
    scene->addItem(R1);
    scene->addItem(L1);
    m.setMinimumWidth(1000);
    m.setWindowTitle("Joystick");


   // scene->addItem(X1);

//  scene->addItem(plus1);
    //m.show();
}

void joystickWindow::axisSet(int x0,int x1,int x2,int x3,int x4,int x5)
{
    redrawPoints(2,x3,x4);
    redrawPoints(1,x0,x1);
    int Radd = (x5+32767)*200/(32767*2);
    int Ladd = (x2+32767)*200/(32767*2);
    L1->setLine(775,250-Ladd,810,250-Ladd);
    R1->setLine(845,250-Radd,880,250-Radd);
}

void joystickWindow::buttonPress(int b)
{
    QString BUT;
    switch(b)
    {
    case 0:
        BUT = "A";
        break;
    case 1:
        BUT = "B";
        break;
    case 2:
        BUT = "X";
        break;
    case 3:
        BUT = "Y";
        break;
    case 4:
        BUT = "L1";
        break;
    case 5:
        BUT = "R1";
        break;
    case 6:
        BUT = "Select";
        break;
    case 7:
        BUT = "Start";
        break;
    default:
        BUT = QString::number(b);


    }

    ButtonTerminal->appendPlainText(BUT);

}

void joystickWindow::showBox()
{
    if(m.isHidden())
    {
        m.show();
    } else
    {
        m.hide();
    }
}

void joystickWindow::redrawPoints(int x, int x1, int x2)
{
    int Xadd = x1*100/32767;
    int Yadd = x2*100/32767;

    if(x == 1)
    {
        X1->setLine(400+Xadd,150+Yadd,420+Xadd,150+Yadd);
        Y1->setLine(410+Xadd,140+Yadd,410+Xadd,160+Yadd);
    }else if (x = 2)
    {
        X2->setLine(640+Xadd,150+Yadd,660+Xadd,150+Yadd);
        Y2->setLine(650+Xadd,140+Yadd,650+Xadd,160+Yadd);
    }
}


