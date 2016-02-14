#include <QtWidgets>
#include "tictactoegameengine.h"
#include "boardwidget.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    TicTacToeGameEngine engine;
    BoardWidget w;
    w.setGameEngine(&engine);

    QObject::connect(&w, SIGNAL(clicked(int,int)),
                     &engine, SLOT(play(int,int)));

    w.show();

    return app.exec();
}
