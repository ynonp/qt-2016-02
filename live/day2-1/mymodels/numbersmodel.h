#ifndef NUMBERSMODEL_H
#define NUMBERSMODEL_H

#include <QtGui>

class NumbersModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit NumbersModel(QObject *parent = NULL);

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;

    // QAbstractItemModel interface
public:
    virtual int columnCount(const QModelIndex &parent) const;


private:
    QList<int> m_items;

    // QAbstractItemModel interface
public:
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role);
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;
};

#endif // NUMBERSMODEL_H










