#include "tictactoegameengine.h"

const QString BLANK = " ";

TicTacToeGameEngine::TicTacToeGameEngine(QObject *parent) : QObject(parent)
{
    for(int i=0; i<9; i++)
    {
        m_data[i] = BLANK;
    }
    m_currentPlayer = "X";
    m_winner = BLANK;

}

bool TicTacToeGameEngine::play(int row, int col)
{
    return play(indexFromRowAndCol(row, col));
}

bool TicTacToeGameEngine::play(int index)
{
    if (m_winner != BLANK)
    {
        // Game over...
        return false;
    }

    if (m_data[index] == BLANK)
    {
        m_data[index] = m_currentPlayer;
        if (checkWinner(m_currentPlayer) == m_currentPlayer)
        {
            m_winner = m_currentPlayer;
            emit winnerChanged();
        }
        else
        {
            nextRound();
        }
        QPair<int,int> pos = rowAndColumnFromIndex(index);
        emit dataChanged(pos.first, pos.second);
        return true;

    }
    return false;
}

QString TicTacToeGameEngine::winner() const
{
    return m_winner;
}

QString TicTacToeGameEngine::valueAt(int row, int col)
{
    return valueAt(indexFromRowAndCol(row, col));
}

QString TicTacToeGameEngine::valueAt(int index)
{
    return m_data[index];
}

void TicTacToeGameEngine::nextRound()
{
    if (m_currentPlayer == "X")
    {
        m_currentPlayer = "O";
    }
    else
    {
        m_currentPlayer = "X";
    }
}

int TicTacToeGameEngine::indexFromRowAndCol(int row, int col) const
{
    return row * 3 + col;
}

QPair<int,int> TicTacToeGameEngine::rowAndColumnFromIndex(int index) const
{
    return QPair<int, int>(index/3, index%3);
}

QString TicTacToeGameEngine::blank()
{
    return BLANK;
}

QString TicTacToeGameEngine::checkWinner(const QString &player)
{
    if ((m_data[0] == player) && (m_data[1] == player) && (m_data[2] == player))
    {
        return player;
    }
    else if ((m_data[3] == player) && (m_data[4] == player) && (m_data[5] == player))
    {
        return player;
    }
    else if ((m_data[6] == player) && (m_data[7] == player) && (m_data[8] == player))
    {
        return player;
    }
    else if ((m_data[0] == player) && (m_data[3] == player) && (m_data[6] == player))
    {
        return player;
    }
    else if ((m_data[1] == player) && (m_data[4] == player) && (m_data[7] == player))
    {
        return player;
    }
    else if ((m_data[2] == player) && (m_data[5] == player) && (m_data[8] == player))
    {
        return player;
    }
    else if ((m_data[0] == player) && (m_data[4] == player) && (m_data[8] == player))
    {
        return player;
    }
    else if ((m_data[2] == player) && (m_data[4] == player) && (m_data[6] == player))
    {
        return player;
    }

    return "";
}
