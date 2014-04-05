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
    int arm1Length;
    int arm2Length;
    int x0;
    int y0;
    void repaint(); //Called after any variables are updated - reapints window
    int Dangle1;    //Base Angle
    int Dangle2;    //Elbow Angle

public:
    explicit armWindow(QObject *parent = 0);
    QGraphicsView m;
    QGraphicsScene *scene;
    QGraphicsLineItem *Arm1;
    QGraphicsLineItem *Arm2;
    QGraphicsRectItem *leftClaw;
    QGraphicsRectItem *rightClaw;

signals:

public slots:
    void Angle1(int A);  //Set base angle - From Slider
    void Angle2(int A); //Set elbow Angle - From slider
    void Buttons(int A);    //Open and close window
    void ClawAngle(int A);  //Open and close Claw

};

#endif // ARMWINDOW_H
