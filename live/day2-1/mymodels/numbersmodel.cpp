#include "numbersmodel.h"

NumbersModel::NumbersModel(QObject *parent):
    QAbstractListModel(parent)
{

}



int NumbersModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return 5;
}

QVariant NumbersModel::data(const QModelIndex &index,
                            int role) const
{
    qDebug() << "Data!" << index << role;
    if (role == Qt::DisplayRole)
    {
        return index.row() * 2;
    }
    else if (role == Qt::BackgroundRole)
    {
        if (index.row() == 2)
        {
            QVariant r;
            r.setValue<QColor>(Qt::yellow);
            return r;
        }
        else
        {
            return QVariant();
        }
    }
    else
    {
        return QVariant();
    }
}













