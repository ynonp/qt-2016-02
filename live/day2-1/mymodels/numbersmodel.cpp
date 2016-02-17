#include "numbersmodel.h"

NumbersModel::NumbersModel(QObject *parent):
    QAbstractTableModel(parent)
{
    for (int i=2; i < 7; i++)
    {
        m_items << i;
    }
}



int NumbersModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return 4;
}

QVariant NumbersModel::data(const QModelIndex &index,
                            int role) const
{
    // qDebug() << "Data!" << index << role;
    if (role == Qt::DisplayRole)
    {                
        if (index.row() < m_items.size())
        {
            int base = m_items[index.row()];
            return qPow(base, index.column()+1);
        }
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

    return QVariant();
}


int NumbersModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

















bool NumbersModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole)
    {
        m_items[index.row()] = value.toInt();
        return true;
    }

    return false;
}

Qt::ItemFlags NumbersModel::flags(const QModelIndex &index) const
{
    if (index.column() == 0)
    {
        return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
    }
    else
    {
        return QAbstractTableModel::flags(index);
    }
}
















