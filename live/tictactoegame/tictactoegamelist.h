#ifndef TICTACTOEGAMELIST_H
#define TICTACTOEGAMELIST_H
#include <QtWidgets>
#include <QtGui>
#include <QtCore>

class TicTacToeGameEngine;


class TicTacToeGameList : public QAbstractListModel
{
    Q_OBJECT

public:    
    Q_PROPERTY(QString winner READ winner NOTIFY winnerChanged)
    TicTacToeGameList(TicTacToeGameEngine &engine, QObject *parent = NULL);

    enum CellRoles {
        ValueRole = Qt::UserRole + 1
    };

    QString winner() const;

    QHash<int, QByteArray> roleNames() const;

signals:
    void winnerChanged();

    // QAbstractItemModel interface

public:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;

    Q_INVOKABLE void play(int idx);

private slots:
    void forwardDataChanged(int row, int column);

private:
    TicTacToeGameEngine &m_engine;
};

#endif // TICTACTOEGAMELIST_H
