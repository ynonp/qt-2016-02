#include "mainwindow.h"
#include <QApplication>
#include <QtCore/QTranslator>
#include <QtCore/QLocale>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load(":/app_he");
    a.installTranslator(&translator);

    qDebug() << QLocale::system().name();

    MainWindow w;
    w.show();

    return a.exec();
}
