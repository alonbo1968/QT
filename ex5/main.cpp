#include <QCoreApplication>
#include <iostream>


int increment_val(int *p_x) {
    (*p_x)++;
    return *p_x;
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


    int x = 5;
    int *px = &x;
    std::cout << "x = " << *px << std::endl;
    std::cout << "call increment_val(px).." << std::endl;
    std::cout << "x = " << increment_val(px) << std::endl;

    a.exit();
    //a.quit();
    //return a.exec();
}
