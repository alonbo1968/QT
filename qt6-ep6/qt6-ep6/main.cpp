#include <QCoreApplication>
#include <QDebug>
#include <memory.h>
#include "house.h"

void do_stuff() {
    //Qt parent-child relationship

    //std::unique_ptr<House> p_parent  {new House(nullptr, "parent")};

    House* p_parent = new House(nullptr, "Parent");

    House* p_house1 = new House(p_parent, "House1");
    House* p_house2 = new House(p_parent, "House2");

    //Deleting p_parent will delete also p_house1/2 due to
    delete p_parent;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    qDebug() << "Demonstrate how objects memory is released without with one delete, by parent-child relationships";
    qDebug() << "Note! This demo has warnings. Not sure if it is 100% correct!";
    qDebug() << "Starting..";
    do_stuff();
    qDebug() << "Ending...";

    return a.exec();
}
