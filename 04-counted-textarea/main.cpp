#include "mainwindow.h"
#include <QApplication>
#include "countedtextarea.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    CountedTextarea w;
    w.show();

    return a.exec();
}
