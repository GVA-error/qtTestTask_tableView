#include "testtabledelegate.h"
#include "../../Settings/settings.h"

TestTableDelegate::TestTableDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{
}

void TestTableDelegate::initStyleOption(QStyleOptionViewItem *option, const QModelIndex &index) const
{
    QStyledItemDelegate::initStyleOption(option, index);

    if (isTimeToHighlightRow(index.row()))
    {
        QBrush normalText = option->palette.brush(QPalette::ColorGroup::Normal, QPalette::ColorRole::Text);
        option->palette.setBrush(QPalette::ColorGroup::Normal, QPalette::ColorRole::Highlight, Qt::gray);
        option->palette.setBrush(QPalette::ColorGroup::Normal, QPalette::ColorRole::HighlightedText, normalText);
        option->backgroundBrush = QColor(Settings::HIGHLIGHT_COLOR);
    }
}

bool TestTableDelegate::isTimeToHighlightRow(qint32 row) const
{
    return (row+1) % Settings::HIGHLIGHT_FREQ == 0;
}
