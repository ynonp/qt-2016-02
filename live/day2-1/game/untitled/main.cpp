#include <QtWidgets>
#include <QtGui>
#include "tictactoegameengine.h"
#include "boardwidget.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    TicTacToeGameEngine engine;
    BoardWidget w;
    BoardWidget t;

    w.setGameEngine(&engine);
    w.show();

    t.setGameEngine(&engine);
    t.show();

    GameModel *model = new GameModel();
    model->setGameEngine(&engine);

    QTableView v;
    v.setModel(model);
    v.show();



    return app.exec();
}





