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
    QGraphicsRectItem *FL;
    QGraphicsRectItem *ML;
    QGraphicsRectItem *BL;
    QGraphicsRectItem *FR;
    QGraphicsRectItem *MR;
    QGraphicsRectItem *BR;
    QGraphicsRectItem *Power;

signals:

public slots:
    void showRover();
    void axisSteer(int x0,int x1,int x2,int x3,int x4,int x5);
    void buttonControl(int but);

};

#endif // ROVERWINDOW_H
