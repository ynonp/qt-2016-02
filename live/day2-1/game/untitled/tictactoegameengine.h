#ifndef TICTACTOEGAMEENGINE_H
#define TICTACTOEGAMEENGINE_H

#include <QObject>
#include <QPair>

class TicTacToeGameEngine : public QObject
{
    Q_OBJECT
public:
    explicit TicTacToeGameEngine(QObject *parent = 0);

    QString winner() const;
    QString checkWinner(const QString &player);

    QString valueAt(int row, int col);
    QString valueAt(int index);

    int indexFromRowAndCol(int row, int col) const;
    QPair<int,int> rowAndColumnFromIndex(int index) const;

    QString blank();

public slots:
    bool play(int row, int col);
    bool play(int index);

private:
    void nextRound();

signals:
    void winnerChanged();
    void dataChanged(int row, int column);

private:
    QString m_data[9];
    QString m_currentPlayer;
    QString m_winner;
};

#endif // TICTACTOEGAMEENGINE_H
