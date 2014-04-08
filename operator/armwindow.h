#ifndef ARMWINDOW_H
#define ARMWINDOW_H

#include <QObject>
#include <qdebug.h>
#include <QApplication>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPlainTextEdit>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <qmath.h>
#include <QPushButton>

class armWindow : public QObject
{
    Q_OBJECT
private:
    int Link1Length;
    int Link2Length;
    int Link3Length;
    int x0;
    int y0;
    void repaint(); //Called after any variables are updated - reapints window
    int Angle1Degrees;    //Base Angle
    int Angle2Degrees;    //shoulder Angle
    int Angle3Degrees;    //Elbow angle
    int Angle4Degrees;    //Wrist - Bend
    int Angle5Degrees;    //Wrist - Rotate

public:
    explicit armWindow(QObject *parent = 0);
    QGraphicsView m;
    QGraphicsScene *scene;
    QGraphicsLineItem *Link1;
    QGraphicsLineItem *Link2;
    QGraphicsLineItem *Link3;
    QGraphicsRectItem *leftClaw;
    QGraphicsRectItem *rightClaw;

signals:

public slots:
    void Base(int Angle);       //Set base angle    (Degrees)
    void Shoulder(int Angle);   //Set shoulder Angle(Degrees)
    void Elbow(int Angle);      //Set elbow Angle   (Degrees)
    void WristBend(int Angle);  //Set Wrist Bend    (Degrees)
    void WristRotate(int Angle);//Set Wrist Rotate  (Degrees)
    void showWindowButton(int Angle);    //Open and close window
    void ClawAngle(int Angle);  //Open/Close Claw
    void ShowWindowClick();

};

#endif // ARMWINDOW_H
