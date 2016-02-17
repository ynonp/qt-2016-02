#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>

#include "numbersmodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    NumbersModel *model = new NumbersModel;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("numbersModel",
                                             model);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

