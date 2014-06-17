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
    int microSeconds;            //Current Slider Value (MicroSeconds)
    QSlider *SLIDER;            //Pointer of Slider
    explicit Servo(QObject *parent = 0);
    void Initialize(QSlider *one,int servo);
    int upperAngle;         //Max Value in Angles - for slider and Graphical Calculations
    int lowerAngle;         //Min Value in Angles - for slider
    int centerValue;        //Value to Center/Start
    int lowerBound;        //Min Value Microseconds
    int upperBound;       //MaxValue MicroSeconds
    bool echo;
    int map();
    void setServoValue(int microValue);
    void angleRange(int upAngle,int downangle);

signals:
    void toTerminalInternal(QString out);
    void Send(QString out);

public slots:
    void keyboardInput(QString data);
    void sliderChanged(int value);
    void joystickData(int X1,int Y1,int LT,int X2,int Y2,int RT);
    void buttonPress(int a);

};

#endif // WORKER_H
