#ifndef RECEIVESWITCH_H
#define RECEIVESWITCH_H

#include <QObject>
#include <QStringList>
#include <qdebug.h>

class receiveSwitch : public QObject
{
    Q_OBJECT

private:
    QStringList data;
    int dataInterger[15];
public:
    explicit receiveSwitch(QObject *parent = 0);

signals:
    void toTerminalInternal(QString display);
    void resetHeader();
    void Send(QString send);
    void servoAttributes(int x[]);

public slots:
    void interpret(QString receive);

};

#endif // RECEIVESWITCH_H
