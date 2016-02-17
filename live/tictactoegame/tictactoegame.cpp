#include "tictactoegame.h"
#include <QModelIndex>
#include "tictactoegameengine.h"
#include <QtCore>

TicTacToeGame::TicTacToeGame(TicTacToeGameEngine &engine):
    m_engine(engine)
{
    QObject::connect(&m_engine, SIGNAL(winnerChanged()), this, SIGNAL(winnerChanged()));
    QObject::connect(&m_engine, SIGNAL(dataChanged(int,int)), this, SLOT(forwardDataChanged(int,int)));
}


int TicTacToeGame::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}

int TicTacToeGame::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}

QVariant TicTacToeGame::data(const QModelIndex &index, int role) const
{

    if (role == Qt::DisplayRole)
    {
        return m_engine.valueAt(index.row(), index.column());
    }
    else
    {
        return QVariant();
    }
}

void TicTacToeGame::play(int row, int col)
{
    m_engine.play(m_engine.indexFromRowAndCol(row, col));
}

QString TicTacToeGame::winner() const
{
    return m_engine.winner();
}

void TicTacToeGame::forwardDataChanged(int row, int column)
{
    auto at = index(row, column);
    emit dataChanged(at, at);
}



