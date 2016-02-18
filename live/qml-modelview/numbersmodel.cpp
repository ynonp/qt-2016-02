#include "numbersmodel.h"

NumbersModel::NumbersModel(QObject *parent):
    QAbstractListModel(parent)
{

}

QHash<int, QByteArray> NumbersModel::roleNames() const
{
    QHash<int, QByteArray> roleNames;
    roleNames[Qt::DisplayRole] = "value";
    roleNames[Qt::UserRole+1] = "secret";
    return roleNames;
}

int NumbersModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return 20;
}

QVariant NumbersModel::data(const QModelIndex &index,
                            int role) const
{
    // qDebug() << "Data!" << index << role;
    if (role == Qt::DisplayRole)
    {                
        return index.row() * 3;
    }
    else if (role == Qt::UserRole+1)
    {
        return QString("√ %1").arg(index.row() * 3);
    }

    return QVariant();
}















