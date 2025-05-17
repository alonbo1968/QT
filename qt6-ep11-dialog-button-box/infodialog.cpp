#include "infodialog.h"
#include "ui_infodialog.h"
#include <QAbstractButton>

Infodialog::Infodialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Infodialog)
{
    ui->setupUi(this);
}

Infodialog::~Infodialog()
{
    delete ui;
}

// void Infodialog::on_OkPushButton_clicked()
// {
//     m_favorite_os = NULL;
//     QString user_position = ui->positionLineEdit->text();
//     if(!user_position.isEmpty()) {
//         m_position = user_position;
//         if(ui->windowsRadioButton->isChecked()) {
//             m_favorite_os = "Windows";
//         }
//         if(ui->LinuxRadioButton->isChecked()) {
//             m_favorite_os = "Linux";
//         }
//         if(ui->MacRadioButton->isChecked()) {
//             m_favorite_os = "Mac";
//         }

//         if(m_favorite_os == "") {
//             //Reject because no OS was selected
//             reject();
//         }
//         else {
//             //Accept the Dialog
//             accept();
//         }
//     }
//     else {
//         reject();
//     }
// }


// void Infodialog::on_cancelPushButton_clicked()
// {
//     //Reject the Dialog
//     reject();
// }

QString Infodialog::position() const
{
    return m_position;
}

QString Infodialog::favorite_os() const
{
    return m_favorite_os;
}


void Infodialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButton = ui->buttonBox->standardButton(button);
    if(stdButton == QDialogButtonBox::Ok) {
        accept();
        qDebug() << "Ok Button pressed";
    }
    if(stdButton == QDialogButtonBox::Cancel) {
        reject();
        qDebug() << "Cancel Button pressed";
    }
    if(stdButton == QDialogButtonBox::Open) {
        qDebug() << "Open Button pressed";
    }
    if(stdButton == QDialogButtonBox::Save) {
        qDebug() << "Save Button pressed";
    }


}

