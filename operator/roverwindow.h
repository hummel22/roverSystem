#ifndef ROVERWINDOW_H
#define ROVERWINDOW_H


#include <QObject>
#include <QApplication>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPlainTextEdit>
#include <qdebug.h>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>

class roverWindow : public QObject
{
    Q_OBJECT
private:

public:
    explicit roverWindow(QObject *parent = 0);
    void intialize();
    QGraphicsView m;
    QGraphicsScene *scene;
    QGraphicsLineItem *leftView;
    QGraphicsLineItem *rightView;
    QGraphicsRectItem *FowardLeftWheel;
    QGraphicsRectItem *MiddleLeftWheel;
    QGraphicsRectItem *BackLeftWheel;
    QGraphicsRectItem *FrontRightWheel;
    QGraphicsRectItem *MiddleRightWheel;
    QGraphicsRectItem *BackRightWheel;
    QGraphicsRectItem *PowerBar;

signals:

public slots:
    void showWindowClick();
    void showWindowButton(int but);
    void repaint(int Power);
    void frontleftSLOT(int Angle);
    void frontrightSLOT(int Angle);
    void backleftSLOT(int Angle);
    void backrightSLOT(int Angle);
    void panSLOT(int Angle);
    void tiltSLOT(int Angle);


};

#endif // ROVERWINDOW_H
