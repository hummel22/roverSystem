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

    FowardLeftWheel = new QGraphicsRectItem;
    MiddleLeftWheel = new QGraphicsRectItem;
    BackLeftWheel = new QGraphicsRectItem;
    FrontRightWheel = new QGraphicsRectItem;
    MiddleRightWheel = new QGraphicsRectItem;
    BackRightWheel = new QGraphicsRectItem;
    leftView = new QGraphicsLineItem;
    rightView = new QGraphicsLineItem;
    FowardLeftWheel->setRect(60,75,20,35);
    FowardLeftWheel->setBrush(QColor(34,227,9));
    FrontRightWheel->setRect(210,75,20,35);
    FrontRightWheel->setBrush(QColor(34,227,9));
    MiddleLeftWheel->setRect(60,145,20,35);
    MiddleLeftWheel->setBrush(QColor(34,227,9));
    MiddleRightWheel->setRect(210,145,20,35);
    MiddleRightWheel->setBrush(QColor(34,227,9));
    BackLeftWheel->setRect(60,215,20,35);
    BackLeftWheel->setBrush(QColor(34,227,9));
    BackRightWheel->setRect(210,215,20,35);
    BackRightWheel->setBrush(QColor(34,227,9));
    leftView->setLine(145,162,75,92);
    rightView->setLine(145,162,215,92);
    leftView->setPen(QPen(Qt::yellow));
    rightView->setPen(QPen(Qt::yellow));

    scene->addItem(FowardLeftWheel);
    scene->addItem(FrontRightWheel);
    scene->addItem(MiddleLeftWheel);
    scene->addItem(MiddleRightWheel);
    scene->addItem(BackLeftWheel);
    scene->addItem(BackRightWheel);
    scene->addItem(leftView);
    scene->addItem(rightView);
    scene->addRect(265,90,10,140);
    PowerBar = new QGraphicsRectItem;
    PowerBar->setBrush(QBrush(Qt::green));
    PowerBar->setRect(266,162,8,0);
    scene->addItem(PowerBar);
}


void roverWindow::showWindowClick()
{
    if(m.isHidden())
    {
        m.show();
    } else
    {
        m.hide();
    }
}


void roverWindow::repaint(int Power)
{

    //Rotations are in degrees
    if (Power>0)
    {
        PowerBar->setBrush(QBrush(Qt::green));
        PowerBar->setRect(265,162-Power,10,Power);
    } else
    {
        PowerBar->setBrush(QBrush(Qt::red));
        PowerBar->setRect(265,162,10,-Power);
    }


}

//Open/Close Window on button Press
void roverWindow::showWindowButton(int but)
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

void roverWindow::frontleftSLOT(int Angle)
{
    FowardLeftWheel->setTransform(QTransform().translate(70, 92).rotate(Angle).translate(-70, -92));
}

void roverWindow::frontrightSLOT(int Angle)
{
    FrontRightWheel->setTransform(QTransform().translate(220, 92).rotate(Angle).translate(-220, -92));
}

void roverWindow::backleftSLOT(int Angle)
{
    BackLeftWheel->setTransform(QTransform().translate(70, 232).rotate(Angle).translate(-70, -232));
}

void roverWindow::backrightSLOT(int Angle)
{
    BackRightWheel->setTransform(QTransform().translate(220, 232).rotate(Angle).translate(-220, -232));
}

void roverWindow::panSLOT(int Angle)
{
    leftView->setTransform(QTransform().translate(142, 162).rotate(Angle).translate(-142, -162));
    rightView->setTransform(QTransform().translate(142, 162).rotate(Angle).translate(-142, -162));
}

void roverWindow::tiltSLOT(int Angle)
{

}
