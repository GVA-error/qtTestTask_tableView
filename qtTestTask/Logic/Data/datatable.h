#ifndef DATATABLE_H
#define DATATABLE_H

#include <QtTypes>
#include <QtLogging>
#include <QString>
#include <QHash>
#include <QPair>
#include <QRandomGenerator>

class DataTable
{
    const QString UNDEFINED_FIELD = QString("UNDEFINED");
public:
    enum class DataType
    {
        Undefined,

        Random,
        IndexData
    };

    DataTable();
    void init(qint32 rowNumber=-1, qint32 columnNumber=-1, DataType type=DataType::IndexData);

    QString data(qint32 row, qint32 column) const;
    qint32 rowCount() const;
    qint32 columnCount() const;

private:
    DataType dataType = DataType::Undefined;
    qint32 mRowNumber;
    qint32 mColumnNumber;
    QHash<QPair<qint32, qint32>, QString> randomDataHash;

    QString formatIndexData(qint32 row, qint32 column) const;
    QString formatRandomData(qint32 row, qint32 column) const;
    void addRandomData(qint32 rB, qint32 rE, qint32 cB, qint32 cE);
};

#endif // DATATABLE_H
