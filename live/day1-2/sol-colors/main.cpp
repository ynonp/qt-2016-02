#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    QVBoxLayout *layout = new QVBoxLayout(&w);

    layout->addWidget(new MainWindow);
    layout->addWidget(new MainWindow);
    layout->addWidget(new MainWindow);

    w.show();
    return a.exec();
}
