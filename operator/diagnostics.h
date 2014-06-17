#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

#include <QObject>
#include <QApplication>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPlainTextEdit>
#include <QGraphicsLineItem>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QComboBox>
#include <QGraphicsGridLayout>
#include <worker.h>


class Diagnostics : public QObject
{
    Q_OBJECT
private:
    QList<QString> servoNames;
    QList<QTextEdit*> Uppers;
    QList<QTextEdit*> Lowers;
    QList<QTextEdit*> Filters;
    QList<QTextEdit*> Centers;
    QList<QLabel*> statusLabels;
    QList<QPushButton*> updateButtons;

    QList<QTextEdit*> motorUpper;

    QList<QString> itemStrings;
    QList<QLabel*> itemStatus;
    QList<QTextEdit*> itemText;
    QList<QPushButton*> itemButton;
    QList<Servo*> servoList;
public:
    explicit Diagnostics(QObject *parent = 0);
    QGraphicsView m;
    QGraphicsScene *scene;

signals:
    void toInternalTerminal(QString send);
    void Send(QString send);


public slots:
    void showWindow();                      //Open/hide Diagnostics Windows
    void updateButton();                    //Slot for Buttons
    void receiveAttributes(int x[]);        //Receive Attributes from interpreter
    void syncAll();



};

#endif // DIAGNOSTICS_H
