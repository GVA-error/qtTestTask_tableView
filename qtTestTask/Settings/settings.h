#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QColor>

namespace Settings
{
    const QString LOG_FILE_NAME         = "./Log.log";
    const qint32  DEFALT_ROW_NUMBER     = 100;
    const qint32  DEFALT_COLUMN_NUMBER  = 100;
    const qint32  HIGHLIGHT_FREQ        = 10;
    const QColor  HIGHLIGHT_COLOR       = QColor(183, 220, 236);
}

#endif // SETTINGS_H
