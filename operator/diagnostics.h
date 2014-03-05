#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

#include <QObject>

class Diagnostics : public QObject
{
    Q_OBJECT
public:
    explicit Diagnostics(QObject *parent = 0);

signals:

public slots:

};

#endif // DIAGNOSTICS_H
