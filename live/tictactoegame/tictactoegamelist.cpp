#include "tictactoegamelist.h"
#include "tictactoegameengine.h"

TicTacToeGameList::TicTacToeGameList(TicTacToeGameEngine &engine, QObject *parent):
    QAbstractListModel(parent),
    m_engine(engine)
{
    QObject::connect(&m_engine, SIGNAL(winnerChanged()), this, SIGNAL(winnerChanged()));
    QObject::connect(&m_engine, SIGNAL(dataChanged(int,int)), this, SLOT(forwardDataChanged(int,int)));
}

QString TicTacToeGameList::winner() const
{
    return m_engine.winner();
}

QHash<int, QByteArray> TicTacToeGameList::TicTacToeGameList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "value";
    return roles;
}



int TicTacToeGameList::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 9;
}

QVariant TicTacToeGameList::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return m_engine.valueAt(index.row());
    }
    else
    {
        return QVariant();
    }
}

void TicTacToeGameList::play(int idx)
{
    m_engine.play(idx);
}

void TicTacToeGameList::forwardDataChanged(int row, int column)
{
    QModelIndex at  = index(m_engine.indexFromRowAndCol(row, column));
    emit dataChanged(at, at);
}

