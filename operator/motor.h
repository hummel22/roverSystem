#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>

class Motor : public QObject
{
    Q_OBJECT
private:
    int UpperLimit;
public:
    explicit Motor(QObject *parent = 0);

signals:

public slots:
    void UpdateLimit();

};

#endif // MOTOR_H
