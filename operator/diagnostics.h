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
public:
    explicit Diagnostics(QObject *parent = 0);
    QGraphicsView m;
    QGraphicsScene *scene;

signals:
    void toInternalTerminal(QString send);

public slots:
    void showDiagnostics();
    void updateButton();



};

#endif // DIAGNOSTICS_H
