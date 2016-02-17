#ifndef NUMBERSMODEL_H
#define NUMBERSMODEL_H

#include <QtGui>

class NumbersModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit NumbersModel(QObject *parent = NULL);

    void setActivePage(int page);


    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
};

#endif // NUMBERSMODEL_H
