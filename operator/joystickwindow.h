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
    void redrawPoints(int x, int x1, int x2);


public:
    explicit joystickWindow(QObject *parent = 0);
    void initialize();
    QGraphicsView m;
    QPlainTextEdit *ButtonTerminal;
    QGraphicsScene *scene;
    QGraphicsLineItem *X1;
    QGraphicsLineItem *Y1;
    QGraphicsLineItem *X2;
    QGraphicsLineItem *Y2;
    QGraphicsLineItem *L1;
    QGraphicsLineItem *R1;

signals:

public slots:
    void axisSet(int x0,int x1,int x2,int x3,int x4,int x5);
    void buttonPress(int b);
    void showBox();

};

#endif // JOYSTICKWINDOW_H
