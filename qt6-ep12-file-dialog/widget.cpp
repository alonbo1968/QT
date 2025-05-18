#include "widget.h"
#include "./ui_widget.h"
 #include <QFileDialog>
#include <QDebug>

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


void Widget::on_chooseButton_clicked()
{
    /*
    //Get Existing Directory
    QString dir = QFileDialog::getExistingDirectory(
        this,
        "Open Directory",
        QString(),
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
    );

    if(!dir.isEmpty()) {
        qDebug() << "Your chosen directory is " << dir;
    }
    else {
        qDebug() << "You did not choose any folder!";
    }
*/

/*
    //Get Open File Name
    QString file_name = QFileDialog::getOpenFileName(
        this,
        "Open file",
        QString(),
        "All (*.*);; text (*.txt);; source (*.cpp)"
        );

    if(!file_name.isEmpty()) {
        qDebug() << "File opened is:" << file_name;
    }
    else {
        qDebug() << "File not opened!";
    }
*/

/*
    //Get Open File Names (multiple files)
    QStringList files_open = QFileDialog::getOpenFileNames(
            this,
            "Select one or more files to open",
            QString(),
            "Source files (*.cpp);; Header files (*.h);; All files (*.*)"
        );
    if(!files_open.isEmpty()) {
        //Print sequebtialy:
        qDebug() << "File opened are:" << files_open;
        //print line ny line:
        for(auto f : files_open) {
            qDebug() << f;
        }
    }
    else {
        qDebug() << "Files not opened!";
    }
*/

/*
    //Get Open File Names (multiple files)
    QString file_save = QFileDialog::getSaveFileName(
        this,
        tr("Save File"),
        //QString(),
        "/home/alon/work",
        tr("Source files (*.cpp)")
        );

    qDebug() << "File saved" << file_save;
*/


    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "/home/alon/work/QT/qt6-ep12-file-dialog",
                                                    tr("Images (*.png *.xpm *.jpg);; Source(*.cpp)"));
    qDebug() << "Your chosen file name is: " << fileName;



}

