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
    QList<Servo*> workerList;
   
public:
    explicit ArmController(QObject *parent = 0);
    void addWorker(Servo *temp);
    

signals:
    void WorkerAllToTerminalInternal(QString out);
    void WorkerAllToSend(QString out);

public slots:
    void keyInput(QString data);
    void axisR(int x0,int x1,int x2,int x3,int x4,int x5);
    void updateMinMax(int workerNumber,int Upper,int Lower);
    void reset();
};

#endif // WORKERALL_H
