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
    scene->setBackgroundBrush(QColor(112,244,213));
    m.setScene(scene);
    scene->addEllipse(310,50,200,200,QColor(0,0,0),QColor(51,102,153));
    scene->addEllipse(550,50,200,200,QColor(0,0,0),QColor(51,102,153));
    scene->addLine(410,20,410,280);
    scene->addLine(650,20,650,280);
    scene->addRect(775,50,35,200);
    scene->addRect(845,50,35,200);
    scene->addWidget(ButtonTerminal);
    X1Line = new QGraphicsLineItem;
    Y1Line = new QGraphicsLineItem;
    X2Line = new QGraphicsLineItem;
    Y2Line = new QGraphicsLineItem;
    X1Line->setLine(400,150,420,150);
    X2Line->setLine(640,150,660,150);
    Y1Line->setLine(410,140,410,160);
    Y2Line->setLine(650,140,650,160);
    X1Line->setPen(QPen(Qt::yellow));
    Y1Line->setPen(QPen(Qt::yellow));
    X2Line->setPen(QPen(Qt::yellow));
    Y2Line->setPen(QPen(Qt::yellow));

    L1Bar = new QGraphicsLineItem;
    R1Bar = new QGraphicsLineItem;
    L1Bar->setLine(775,250,810,250);
    R1Bar->setLine(845,250,880,250);
    L1Bar->setPen(QPen(Qt::red));
    R1Bar->setPen(QPen(Qt::red));
    scene->addItem(X1Line);
    scene->addItem(X2Line);
    scene->addItem(Y1Line);
    scene->addItem(Y2Line);
    scene->addItem(R1Bar);
    scene->addItem(L1Bar);
    m.setMinimumWidth(1000);
    m.setWindowTitle("Joystick");


   // scene->addItem(X1);

//  scene->addItem(plus1);
    //m.show();
}

void joystickWindow::joystickData(int X1,int Y1,int LT,int X2,int Y2,int RT)
{
    redrawPoints(2,X2,Y2);  //Right joystick
    redrawPoints(1,X1,Y1);  //Left Joystick

    //Triggers
    int Radd = (RT+32767)*200/(32767*2);
    int Ladd = (LT+32767)*200/(32767*2);
    L1Bar->setLine(775,250-Ladd,810,250-Ladd);      //Redraw LT Bar
    R1Bar->setLine(845,250-Radd,880,250-Radd);      //Redraw RT Bar
}

void joystickWindow::buttonPressed(int b)
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

//Show/Hide Window
void joystickWindow::showWindow()
{
    if(m.isHidden())
    {
        m.show();
    } else
    {
        m.hide();
    }
}

//Redraw Pointers for joysticks
void joystickWindow::redrawPoints(int Joystick, int X, int Y)
{
    int Xadd = X*100/32767;         //Scale to -100/100
    int Yadd = Y*100/32767;

    if(Joystick == 1)  //Left joystick
    {
        X1Line->setLine(400+Xadd,150+Yadd,420+Xadd,150+Yadd);
        Y1Line->setLine(410+Xadd,140+Yadd,410+Xadd,160+Yadd);
    }else if (Joystick = 2)    //Right joystick
    {
        X2Line->setLine(640+Xadd,150+Yadd,660+Xadd,150+Yadd);
        Y2Line->setLine(650+Xadd,140+Yadd,650+Xadd,160+Yadd);
    }
}


