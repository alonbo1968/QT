#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //String notation
    //connect(ui->verticalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
    //connect(ui->verticalSlider, SIGNAL(valueChanged(int)), this, SLOT(respond(int)));

    //Functor notation
    //connect(ui->verticalSlider, &QSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);
    //connect(ui->verticalSlider, &QSlider::valueChanged, this, &Widget::respond);

    //Functor notation - Lambda
    connect(ui->verticalSlider, &QSlider::valueChanged,
            this, [=](){ui->progressBar->setValue(ui->verticalSlider->value());
            respond(ui->verticalSlider->value());
        });
}



Widget::~Widget()
{
    delete ui;
}

void Widget::respond(int value)
{
    qDebug() << "Slider bar value: " << value;
}


