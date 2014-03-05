#ifndef HRADIOBUTTON_H
#define HRADIOBUTTON_H

#include <QRadioButton>
#include <QEvent>

class HRadioButton : public QRadioButton
{
    Q_OBJECT
private:
    int ButtonIdentifier;
public:
    explicit HRadioButton(QWidget *parent = 0);
    void initialize(int identifier);

signals:
    void clicked(int num);
    void RadioButtontoTerminalInternal(QString message);


public slots:
    void toggledOn(bool onOff);

};

#endif // HRADIOBUTTON_H
