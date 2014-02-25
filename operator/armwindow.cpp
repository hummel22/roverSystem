#include "armwindow.h"

armWindow::armWindow(QObject *parent) :
    QObject(parent)
{
    scene = new QGraphicsScene(0,0,300,500,&m);
    scene->setBackgroundBrush(QColor(51,102,153));
    m.setScene(scene);
    m.setWindowTitle("Arm");
    m.setMinimumHeight(500);
    m.setMinimumWidth(300);
    scene->addLine(0,120,300,120);
    scene->addRect(20,300,250,50);
    Arm1 = new QGraphicsLineItem;
    Arm2 = new QGraphicsLineItem;
    arm1Length = 100;
    arm2Length = 80;
    x0 = 15;
    y0 = 120;
    Dangle1 = 5;
    Dangle2 = 5;
    double angle1 = Dangle1*3.1415926535/180;
    double angle2 = Dangle2*3.14159265353/180;
    int P1x = x0 + arm1Length*qCos(angle1);
    int P1y = y0 - arm1Length*qSin(angle1);
    int P2x = P1x + arm2Length*qCos(3.1415926535-angle1-angle2);
    int P2y = P1y + arm2Length*qSin(3.1415926535-angle1-angle2);

    Arm1->setLine(x0,y0,P1x,P1y);
    Arm2->setLine(P1x,P1y,P2x,P2y);
    scene->addItem(Arm1);
    scene->addItem(Arm2);
    leftClaw = new QGraphicsRectItem;
    rightClaw = new QGraphicsRectItem;
    leftClaw->setRect(20,250,20,50);
    rightClaw->setRect(250,250,20,50);
    scene->addItem(leftClaw);
    scene->addItem(rightClaw);
}

void armWindow::repaint()
{
    double angle1 = Dangle1*3.1415926535/180;
    double angle2 = Dangle2*3.14159265353/180;
    int P1x = x0 + arm1Length*qCos(angle1);
    int P1y = y0 - arm1Length*qSin(angle1);
    int P2x = P1x + arm2Length*qCos(3.1415926535-angle1-angle2);
    int P2y = P1y + arm2Length*qSin(3.1415926535-angle1-angle2);
    Arm1->setLine(x0,y0,P1x,P1y);
    Arm2->setLine(P1x,P1y,P2x,P2y);
}

void armWindow::Angle1(int A)
{
    Dangle1 = A;
    repaint();
}

void armWindow::Angle2(int A)
{
    Dangle2 = A;
    repaint();
}

void armWindow::Buttons(int A)
{
    if(A == 6)
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

void armWindow::ClawAngle(int A)
{
    int Xadd = A*105/180;
    leftClaw->setRect(20+Xadd,250,20,50);
    rightClaw->setRect(250-Xadd,250,20,50);

}
