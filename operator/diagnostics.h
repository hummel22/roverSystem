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
public:
    explicit Diagnostics(QObject *parent = 0);
    QGraphicsView m;
    QGraphicsScene *scene;

signals:
    void toInternalTerminal(QString send);
    void Send(QString send);

public slots:
    void showDiagnostics();
    void updateButton();
    void receiveAttributes(QString list);



};

#endif // DIAGNOSTICS_H
