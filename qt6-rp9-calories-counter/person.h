#ifndef PERSON_H
#define PERSON_H

#include <QObject>
//#include "widget.h"

class Person : public QObject
{
    Q_OBJECT
public:
    double get_weight();
    void set_weight(double weight);

signals:
    // void weightChanged();

private:
        double m_weight = 0.0;
};

#endif // PERSON_H
