#ifndef KEYWINDOE_H
#define KEYWINDOE_H

#include <QWidget>
#include <QString>
#include <QKeyEvent>

class keyWindoe : public QWidget
{
    Q_OBJECT
public:
    explicit keyWindoe(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *e);

signals:
    void sendKey(QString keyS);

public slots:

};

#endif // KEYWINDOE_H
