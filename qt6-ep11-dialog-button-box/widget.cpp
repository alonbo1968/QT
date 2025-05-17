#include "widget.h"
#include "./ui_widget.h"
#include "infodialog.h"
#include "dialog2.h"

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

void Widget::on_showInfoButton_clicked()
{
    Infodialog * dialog = new Infodialog(this);
    dialog->exec();

 }

