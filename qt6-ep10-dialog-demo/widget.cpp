#include "widget.h"
#include "./ui_widget.h"
#include "infodialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_provideInfoButton_clicked()
{
    Infodialog * dialog = new Infodialog(this);

    /*
    //Modal dialog
    auto ret = dialog->exec();

    QString position = dialog->position();
    QString os = dialog->favorite_os();

    if(ret == QDialog::Accepted) {
        ui->infoLabel->setText("Your position is: " + position
                               + " and your favorite OS is " + os);
    }
    else {
        ui->infoLabel->setText("Dialog rejected!");
    }
    */


    //Non-Modal dialog
     connect(dialog, &Infodialog::accepted,
            [=](){
            QString position = dialog->position();
            QString os = dialog->favorite_os();
            ui->infoLabel->setText("Your position is " + position
                                   + " and your favorite is " + os);});

    //connect(dialog, &Infodialog::rejected,
    //        [=](){
    //        ui->infoLabel->setText("Dialog rejected!");});

    connect(dialog, &Infodialog::rejected, this, &Widget::dialog_rejected_message);

    dialog->show();
    dialog->raise();
    dialog->activateWindow();
}

void Widget::dialog_rejected_message()
{
    ui->infoLabel->setText("Dialog rejected!!!");
}

