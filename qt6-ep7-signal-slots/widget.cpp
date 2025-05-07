#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // *********** myButton *********************************
    //string notation
    //connect(ui->myButton, SIGNAL(clicked()), this, SLOT(change_text()));

    //Functor notation - regular Slots
    //connect(ui->myButton, &QPushButton::clicked, this, &Widget::change_text);

    //Functor notation - Lambda
    connect(ui->myButton, &QPushButton::clicked, this, [=](){ui->label->setText("SOME OTHER TEXT FROM LAMBDA");});



    // *********** myButton_2 *********************************
    //Functor notation - regular Slots
    connect(ui->myButton_2, &QPushButton::clicked, this, &Widget::on_myButton_2_clicked);
    //Functor notation - Lambda
    connect(ui->myButton_2, &QPushButton::clicked, this, [=](){ui->label_2->setText("myButton_2 - LAMBDA");});

}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_text()
{
    ui->label->setText("Some other label");
}

//This function is created by selecting myButto_2 Right-Mouse option "Go to Slot"!
void Widget::on_myButton_2_clicked()
{
    ui->label_2->setText("myButton_2 Clicked!!!");
}

