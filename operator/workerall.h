#ifndef WORKERALL_H
#define WORKERALL_H

#include <QObject>
#include <worker.h>
#include <QList>
#include <qdebug.h>
#include <QApplication>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPlainTextEdit>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <qmath.h>

class ArmController : public QObject
{
    Q_OBJECT
private:
    QList<Servo*> servoList;
   
public:
    explicit ArmController(QObject *parent = 0);
    void addWorker(Servo *temp);
    

signals:
    void toTerminalInternal(QString out);
    void Send(QString out);

public slots:
    void keyInput(QString data);
    void joystickData(int X1,int Y1,int LT,int X2,int Y2,int RT);
    void reset();
};

#endif // WORKERALL_H
