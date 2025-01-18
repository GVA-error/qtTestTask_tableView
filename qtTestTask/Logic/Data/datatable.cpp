#include "datatable.h"

#include "../../Settings/settings.h"
#include <qdebug.h>

DataTable::DataTable() {}

void DataTable::init(qint32 rowNumber, qint32 columnNumber, DataType type)
{
    if (type == DataType::Undefined)
    {
        qWarning() << "DataTable is not defined";
        return;
    }
    dataType = type;

    if (rowNumber == -1)
        mRowNumber = Settings::DEFALT_ROW_NUMBER;
    else
        mRowNumber = rowNumber;

    if (columnNumber == -1)
        mColumnNumber = Settings::DEFALT_COLUMN_NUMBER;
    else
        mColumnNumber = columnNumber;

    if (dataType == DataType::Random)
        addRandomData(0, mRowNumber, 0, mColumnNumber);

    if (mRowNumber <= 0 || mColumnNumber <= 0)
    {
        qCritical() << "DataTable is incorrect";
    }
}

QString DataTable::data(qint32 row, qint32 column) const
{
    if (dataType == DataType::IndexData)
        return formatIndexData(row, column);
    if (dataType == DataType::Random)
    {
        QPair k = {row, column};
        if (randomDataHash.find(k) == randomDataHash.end())
        {
            qWarning() << QString("Data in cell [%1, %1] not found").arg(row, column);
            return UNDEFINED_FIELD;
        }
        return randomDataHash[k];
    }

    qWarning() << "Data not found";
    return UNDEFINED_FIELD;
}

QString DataTable::formatIndexData(qint32 row, qint32 column) const
{
    return "l: " + QString::number(row+1) + "." + QString::number(column+1);
    //return QString("l: %1_%1").arg(row+1, column+1); // alternative view
}

QString DataTable::formatRandomData(qint32 row, qint32 column) const
{
    return QString("r: %1").arg(QRandomGenerator::global()->generate()); // alternative view
}

void DataTable::addRandomData(qint32 rB, qint32 rE, qint32 cB, qint32 cE)
{
    for (qint32 i = rB; i<rE; i++)
        for (qint32 j = cB; j<cE; j++)
            randomDataHash[{i, j}] = formatRandomData(i, j);
}

qint32 DataTable::rowCount() const
{
    return mRowNumber;
}

qint32 DataTable::columnCount() const
{
    return mColumnNumber;
}
