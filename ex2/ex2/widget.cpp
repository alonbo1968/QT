#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Initialize
    srand(time(NULL));

    //Generate random between 1 to 10
    secretNumber = rand() % 10 + 1;
    qDebug() << "Secret Number = " << QString::number(secretNumber);
    ui->messageLabel->setText("");
}


Widget::~Widget()
{
    delete ui;
}

void Widget::on_guessButton_clicked()
{
    guessNumber = ui->spinBox->value();
    qDebug() << "guess number = " << QString::number(guessNumber);

    if(guessNumber == secretNumber) {
        ui->messageLabel->setText("Correct! Number is " +QString::number(secretNumber));

        //Disable the geuss button
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setEnabled(true);
    }
    else {
        if(guessNumber > secretNumber) {
            ui->messageLabel->setText("Try smaller number");
        }
        else {
            ui->messageLabel->setText("Try bigger number");
        }
    }
}

void Widget::on_startOverButton_clicked()
{
    secretNumber = rand() % 10 + 1;
    qDebug() << "Secret Number = " << QString::number(secretNumber);
    ui->guessButton->setDisabled(false);
    ui->startOverButton->setDisabled(true);
    ui->spinBox->setValue(1);
    //ui->messageLabel->clear();
    ui->messageLabel->setText("");
}
