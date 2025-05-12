#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //In this example, i use deliberatly two connect() functions. I could
    // implement this using one connect() by adding setting label2 text inside
    // the inc_button1() function

    counter = 0;
    connect(ui->pushButton1, &QPushButton::clicked, this, &Widget::inc_button1);

    //connect using Lambda function
    connect(this, &Widget::press_count, [=](){ui->label2->setText(QString::number(counter));});

    //connect using string notation
    //connect(ui->pushButton1, SIGNAL(clicked()), this, SLOT(update_label()));

    //connect using Functor notation
    //connect(this, &Widget::press_count, this, &Widget::update_label);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::inc_button1() {
    counter++;
    emit press_count();
}

void Widget::update_label() {

    ui->label2->setText(QString::number(counter));
}
