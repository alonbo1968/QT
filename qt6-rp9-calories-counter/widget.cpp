#include "widget.h"
#include "./ui_widget.h"
#include "person.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Initialize the members from the values in the ui
    m_person.set_weight(ui->weightSpinBox->value());
    m_time = ui->timeSpinBox->value();
    m_speed = ui->speedSpinBox->value();

    //Connect to the SpinBoxes
    connect(ui->weightSpinBox, &QDoubleSpinBox::valueChanged, this, &Widget::weight_changed);
    connect(ui->timeSpinBox, &QDoubleSpinBox::valueChanged, this, &Widget::time_changed);
    connect(ui->speedSpinBox, &QDoubleSpinBox::valueChanged, this, &Widget::speed_changed);

    //Update the Calory Count when necessary
    connect(this, &Widget::calory_count_changed, [=](){ui->caloryCountLabel->setText(QString::number(m_calory_count));});

}

Widget::~Widget()
{
    delete ui;
}

void Widget::calculate_calories()
{
    m_calory_count =
        ((0.0215*(m_speed*m_speed*m_speed) - (0.1765*(m_speed*m_speed))
                       +(0.8710*m_speed)+1.4577)*m_person.get_weight()*m_time);
    emit calory_count_changed();
}

void Widget::weight_changed(double weight)
{
    m_person.set_weight(weight);
    calculate_calories();
}

void Widget::time_changed(double time)
{
    m_time = time;
    calculate_calories();
}

void Widget::speed_changed(double speed)
{
    m_speed = speed;
    calculate_calories();
}
