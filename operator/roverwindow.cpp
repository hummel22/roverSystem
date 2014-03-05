#include "roverwindow.h"

roverWindow::roverWindow(QObject *parent) :
    QObject(parent)
{
}

void roverWindow::intialize()
{
    scene = new QGraphicsScene(0,0,300,500,&m);
    scene->setBackgroundBrush(QColor(112,244,213));
    m.setScene(scene);
    m.setWindowTitle("Rover");
    m.setMinimumHeight(500);
    m.setMinimumWidth(300);
    scene->addRect(100,90,90,145,QColor(51,102,153),QColor(51,102,153));

    FL = new QGraphicsRectItem;
    ML = new QGraphicsRectItem;
    BL = new QGraphicsRectItem;
    FR = new QGraphicsRectItem;
    MR = new QGraphicsRectItem;
    BR = new QGraphicsRectItem;
    leftView = new QGraphicsLineItem;
    rightView = new QGraphicsLineItem;
    FL->setRect(60,75,20,35);
    FL->setBrush(QColor(34,227,9));
    FR->setRect(210,75,20,35);
    FR->setBrush(QColor(34,227,9));
    ML->setRect(60,145,20,35);
    ML->setBrush(QColor(34,227,9));
    MR->setRect(210,145,20,35);
    MR->setBrush(QColor(34,227,9));
    BL->setRect(60,215,20,35);
    BL->setBrush(QColor(34,227,9));
    BR->setRect(210,215,20,35);
    BR->setBrush(QColor(34,227,9));
    leftView->setLine(145,162,75,92);
    rightView->setLine(145,162,215,92);
    leftView->setPen(QPen(Qt::yellow));
    rightView->setPen(QPen(Qt::yellow));

    scene->addItem(FL);
    scene->addItem(FR);
    scene->addItem(ML);
    scene->addItem(MR);
    scene->addItem(BL);
    scene->addItem(BR);
    scene->addItem(leftView);
    scene->addItem(rightView);
    scene->addRect(265,90,10,140);
    Power = new QGraphicsRectItem;
    Power->setBrush(QBrush(Qt::green));
    Power->setRect(266,162,8,0);
    scene->addItem(Power);
}


void roverWindow::showRover()
{
    if(m.isHidden())
    {
        m.show();
    } else
    {
        m.hide();
    }
}


void roverWindow::axisSteer(int x0, int x1, int x2, int x3, int x4, int x5)
{
    int rot = x0*45/32767;
    int rot2 = x3*90/32767;
    double multiplier1 = (((double)x5)+32767)/(32767*2)+1; //1 to 2
    double multiplier2 = 1-((((double)x2)+32767)*0.5/(32767*2));//From 0.5 to 1
    int pow = -x1*36/32767 * multiplier1*multiplier2;

    if (pow>0)
    {
        Power->setBrush(QBrush(Qt::green));
        Power->setRect(265,162-pow,10,pow);
    } else
    {
        Power->setBrush(QBrush(Qt::red));
        Power->setRect(265,162,10,-pow);
    }

    FL->setTransform(QTransform().translate(70, 92).rotate(rot).translate(-70, -92));
    FR->setTransform(QTransform().translate(220, 92).rotate(rot).translate(-220, -92));
    BL->setTransform(QTransform().translate(70, 232).rotate(-rot).translate(-70, -232));
    BR->setTransform(QTransform().translate(220, 232).rotate(-rot).translate(-220, -232));
    leftView->setTransform(QTransform().translate(142, 162).rotate(rot2).translate(-142, -162));
    rightView->setTransform(QTransform().translate(142, 162).rotate(rot2).translate(-142, -162));


}

void roverWindow::buttonControl(int but)
{
    if(but == 7)
    {
        if(m.isHidden())
        {
            m.show();
        } else
        {
            m.hide();
        }
    }
}
