#include "mainwindow.h"
#include <QApplication>
#include <QtCore>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile f(":/style.qss");
    f.open(QIODevice::ReadOnly);
    QByteArray content = f.readAll();
    f.close();

    qDebug() << "Style = " << content;
    a.setStyleSheet(content);

    qDebug() << QLocale::system().name();

    QTranslator tr;
    tr.load(":app_he");
    a.installTranslator(&tr);

    MainWindow w;
    w.show();


    return a.exec();
}
