#ifndef DEFAULTTABLEMODEL_H
#define DEFAULTTABLEMODEL_H

#include <QWidget>
#include <QAbstractTableModel>
#include <QSharedPointer>

#include "../../Logic/Data/datatable.h"

class DefaultTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit DefaultTableModel(QSharedPointer<DataTable>& data, QWidget *parent = nullptr);

    qint32 rowCount(const QModelIndex &parent = QModelIndex()) const override;
    qint32 columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

signals:

private:
    QSharedPointer<DataTable> mData;
};

#endif // DEFAULTTABLEMODEL_H
