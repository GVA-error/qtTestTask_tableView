#ifndef TESTTABLEDELEGATE_H
#define TESTTABLEDELEGATE_H

#include <QStyledItemDelegate>

class TestTableDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit TestTableDelegate(QObject *parent = nullptr);

    void initStyleOption(QStyleOptionViewItem *option, const QModelIndex &index) const override;

signals:

private:
    bool isTimeToHighlightRow(qint32 row) const;
};

#endif // TESTTABLEDELEGATE_H
