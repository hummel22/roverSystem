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

class armWindow : public QObject
{
    Q_OBJECT
private:
    int arm1Length;
    int arm2Length;
    int x0;
    int y0;
    void repaint();
    int Dangle1;
    int Dangle2;
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
    void Angle1(int A);
    void Angle2(int A);
    void Buttons(int A);
    void ClawAngle(int A);

};

#endif // ARMWINDOW_H
