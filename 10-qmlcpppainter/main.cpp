#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mypainteditem.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<MyPaintedItem>("Shapes", 1, 0, "MyItem");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

