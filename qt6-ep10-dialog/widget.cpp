#include "widget.h"
#include "./ui_widget.h"
#include "infodialog1.h"

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
    InfoDialog1 *dialog1 = new InfoDialog1(this);

    /* Show the dialog in Modal way */
    auto ret = dialog1->exec();

    /* Show the dialog, Non-Modal way */
    //dialog1->show();
    if(ret == QDialog::Accepted) {
        QString position = dialog1->position();
        QString os = dialog1->favorite_os();
        ui->infoLabel->setText("Your position is " + position +
                               " and your favorite OS is " + os);
    }
    else {
        ui->infoLabel->setText("No valis answer!");
    }
}

