#ifndef JOYSTICKWINDOW_H
#define JOYSTICKWINDOW_H

#include <QObject>
#include <QApplication>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPlainTextEdit>
#include <qdebug.h>
#include <QGraphicsLineItem>

class joystickWindow : public QObject
{
    Q_OBJECT
private:
    void redrawPoints(int Joystick, int X, int Y);
    QGraphicsLineItem *X1Line;
    QGraphicsLineItem *Y1Line;
    QGraphicsLineItem *X2Line;
    QGraphicsLineItem *Y2Line;
    QGraphicsLineItem *L1Bar;
    QGraphicsLineItem *R1Bar;


public:
    explicit joystickWindow(QObject *parent = 0);
    void initialize();
    QGraphicsView m;
    QPlainTextEdit *ButtonTerminal;
    QGraphicsScene *scene;


signals:

public slots:
    void joystickData(int X1,int Y1,int LT,int X2,int Y2,int RT);
    void buttonPressed(int b);
    void showWindow();

};

#endif // JOYSTICKWINDOW_H
