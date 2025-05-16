#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class Infodialog;
}

class Infodialog : public QDialog
{
    Q_OBJECT

public:
    explicit Infodialog(QWidget *parent = nullptr);
    ~Infodialog();

    QString position() const;
    QString favorite_os() const;

private slots:
    void on_OkPushButton_clicked();

    void on_cancelPushButton_clicked();

private:
    Ui::Infodialog *ui;
    QString m_position;
    QString m_favorite_os;
};

#endif // INFODIALOG_H
