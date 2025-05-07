#ifndef HOUSE_H
#define HOUSE_H

#include <QObject>
class House : public QObject
{
    Q_OBJECT
public:
    explicit House(QObject *parent = nullptr, const QString& descr = "");
    void print_info() const;
    ~House();
    void print_info();

private:
    QString m_descr;
};
#endif // HOUSE_H
