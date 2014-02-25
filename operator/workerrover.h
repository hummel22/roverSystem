#ifndef WORKERROVER_H
#define WORKERROVER_H

#include <QObject>

class WorkerRover : public QObject
{
    Q_OBJECT
public:
    explicit WorkerRover(QObject *parent = 0);

signals:
    void WorkerRoverToTerminalInternal(QString out);
    void WorkerRoverToSend(QString out);

public slots:
    void keyInput(QString data);
};

#endif // WORKERROVER_H
