#include "mainwindow.h"
#include <QApplication>
#include "counter.h"
#include "mylabel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    MyLabel l("Hello");
    l.show();
    return a.exec();
}
