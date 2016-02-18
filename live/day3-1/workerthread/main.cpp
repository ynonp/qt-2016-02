#include "mainwindow.h"
#include <QApplication>
#include "myfilewriter.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QThread t;
    MyFileWriter writer;
    writer.moveToThread(&t);
    t.start();


    MainWindow w(writer);
    w.show();

    return a.exec();
}
