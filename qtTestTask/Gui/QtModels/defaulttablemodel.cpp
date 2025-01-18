#include "defaulttablemodel.h"

DefaultTableModel::DefaultTableModel(QSharedPointer<DataTable>& data, QWidget *parent)
    : QAbstractTableModel{parent}
{
    mData = data;
}

qint32 DefaultTableModel::rowCount(const QModelIndex & /*parent*/) const
{
    return mData->rowCount();
}

qint32 DefaultTableModel::columnCount(const QModelIndex & /*parent*/) const
{
    return mData->columnCount();
}

QVariant DefaultTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        return mData->data(index.row(), index.column());

    return QVariant();
}

QVariant DefaultTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Orientation::Vertical)
            return QString("V: %1").arg(section+1);
        else
            return QString("H: %1").arg(section+1);
    }
    else
        return QAbstractTableModel::headerData(section, orientation, role);

}
