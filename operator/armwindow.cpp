#include "armwindow.h"

armWindow::armWindow(QObject *parent) :
    QObject(parent)
{
    scene = new QGraphicsScene(0,0,300,500,&m);
    scene->setBackgroundBrush(QColor(112,244,213));
    m.setScene(scene);
    m.setWindowTitle("Arm");
    m.setMinimumHeight(500);
    m.setMinimumWidth(300);


    scene->addLine(0,120,300,120);      //Base Line
    scene->addRect(20,300,250,50);      //Claw Base



    //Origin X-Y of arm
    x0 = 15;
    y0 = 120;

    //Initial Angles
    Angle2Degrees = 5;  //Shoulder Angle
    Angle3Degrees = 5;  //Elbow Angle
    Angle4Degrees = 5;  //Wrist - Bend

    //Geometry Calculations
    Link1Length = 100;
    Link2Length = 80;
    Link3Length = 40;

    Link1 = new QGraphicsLineItem;
    Link2 = new QGraphicsLineItem;
    Link3 = new QGraphicsLineItem;
    //Intial Draw - Arm
    repaint();
    scene->addItem(Link1);
    scene->addItem(Link2);
    scene->addItem(Link3);

    //Intial Draw - Claw
    leftClaw = new QGraphicsRectItem;
    rightClaw = new QGraphicsRectItem;
    leftClaw->setRect(20,250,20,50);
    rightClaw->setRect(250,250,20,50);
    scene->addItem(leftClaw);
    scene->addItem(rightClaw);
}

//Redraw
void armWindow::repaint()
{
    //Convert Degrees to Radians
    double Angle2Radians = Angle2Degrees*3.1415926535/180;
    double Angle3Radians = Angle3Degrees*3.14159265353/180;
    double Angle4Radians = Angle4Degrees*3.14159265353/180;

    //X and Y location of first Joint
    int P1x = x0 + Link1Length*qCos(Angle2Radians);
    int P1y = y0 - Link1Length*qSin(Angle2Radians);

    //X and Y location of second joint
    int P2x = P1x + -1*Link2Length*qCos((3.1415926535-Angle2Radians-Angle3Radians));
    int P2y = P1y + 1*Link2Length*qSin((3.1415926535-Angle2Radians-Angle3Radians));

    //X and Y of Claw Location
    int P3x = P2x - Link3Length*qCos(3.1415926535-Angle2Radians-Angle3Radians-Angle4Radians);
    int P3y = P2y - Link3Length*qSin(3.1415926535-Angle2Radians-Angle3Radians-Angle4Radians);


    //Redraw Lines
    Link1->setLine(x0,y0,P1x,P1y);
    Link2->setLine(P1x,P1y,P2x,P2y);
    Link3->setLine(P2x,P2y,P3x,P3y);
}

//Change Base angle
void armWindow::Base(int Angle)
{

}

//Change Shoulder Angle
void armWindow::Shoulder(int Angle)
{
    Angle2Degrees = Angle;
    repaint();
}

//Change Elbow Angle
void armWindow::Elbow(int Angle)
{
    Angle3Degrees = Angle;
    repaint();
}

//Change Wrist Bend
void armWindow::WristBend(int Angle)
{
    Angle4Degrees = Angle;
    repaint();
}

//Change Wrist Rotate
void armWindow::WristRotate(int Angle)
{

}

//Open and close window with Controller
void armWindow::showWindowButton(int A)
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
void armWindow::ShowWindowClick()
{
    if(m.isHidden())
    {
        m.show();
    } else
    {
        m.hide();
    }
}

//Redraw Claw
void armWindow::ClawAngle(int A)
{
    //Moves claw between 0-105 pixels ratioed from 0 to 180
    int Xadd = A*105/180;
    leftClaw->setRect(20+Xadd,250,20,50);
    rightClaw->setRect(250-Xadd,250,20,50);

}
