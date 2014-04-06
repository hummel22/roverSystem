#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QString>
#include <QSlider>

class Servo : public QObject
{
    Q_OBJECT
private:
    int servoNumber;
    QString sendString;



public:
    int sliderValue;
    QSlider *SLIDER;
    explicit Servo(QObject *parent = 0);
    void Initialize(QSlider *one,int servo);
    int upperAngle;         //Max Value in Angles - for slider
    int lowerAngle;         //Min Value in Angles - for slider
    int centerValue;        //Value to center
    int lowerBound;        //Min Value Microseconds
    int upperBound;       //MaxValue MicroSeconds
    int startPoint;
    bool echo;
    int map();
    void sendForce(int microValue);

signals:
    void ToTerminalInternal(QString out);
    void Send(QString out);

public slots:
    void KeyboardInput(QString data);
    void SliderChanged(int value);
    void JoystickInput(int x0,int x1,int x2,int x3,int x4,int x5);

};

#endif // WORKER_H
