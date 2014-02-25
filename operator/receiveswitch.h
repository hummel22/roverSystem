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
public:
    explicit receiveSwitch(QObject *parent = 0);

signals:
    void toInternal(QString display);
    void resetHeader();
    void toSend(QString send);

public slots:
    void interpret(QString receive);

};

#endif // RECEIVESWITCH_H
