#include <QApplication>
#include <QQmlApplicationEngine>
#include "tictactoegame.h"
#include <QtWidgets>
#include <QtGui>
#include <QDebug>
#include <QQmlContext>
#include "tictactoegameengine.h"
#include "tictactoegamelist.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TicTacToeGameEngine tttEngine;
    TicTacToeGame g(tttEngine);
    TicTacToeGameList gl(tttEngine);

    QQmlApplicationEngine engine;
    auto context = engine.rootContext();
    context->setContextProperty("game", &gl);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QTableView tv;

    tv.setModel(&g);
    tv.show();
    tv.setSelectionMode(QAbstractItemView::NoSelection);

    QObject::connect(&tv, &QTableView::clicked, [&](const QModelIndex &index) {
        if (index.isValid()) {
            qDebug() << "User clicked on: " << index.row() << index.column();
            g.play(index.row(), index.column());
        }
    });

    return app.exec();
}

