#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include <QObject>
#include <QAbstractTableModel>
#include <QtWidgets>
#include <QtGui>
class TicTacToeGameEngine;

class TicTacToeGame : public QAbstractTableModel
{
    Q_OBJECT

public:
    Q_PROPERTY(QString winner READ winner NOTIFY winnerChanged)

    TicTacToeGame(TicTacToeGameEngine &engine);
    // QAbstractItemModel interface

public:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;

    void play(int row, int col);

    QString winner() const;


private slots:
    void forwardDataChanged(int row, int column);

signals:
    void winnerChanged();

private:
    TicTacToeGameEngine &m_engine;
};

#endif // TICTACTOEGAME_H
