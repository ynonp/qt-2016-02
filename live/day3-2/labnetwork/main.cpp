#include "mainwindow.h"
#include <QApplication>
#include <QtQuick>
#include "omdbapi.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QQmlApplicationEngine engine;
    OmdbApi omdb;
    engine.rootContext()->setContextProperty("omdb", &omdb);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return a.exec();
}
