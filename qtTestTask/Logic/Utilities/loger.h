#ifndef LOGER_H
#define LOGER_H

#include <QDebug>
#include <QFile>
#include <QHash>

class Logger {
private:
    static QFile* logFile;
    static bool isInit;
    static QHash<QtMsgType, QString> contextNames;
public:
    static void init();
    static void clean();
    static void messageOutput(QtMsgType type, const QMessageLogContext& context, const QString& msg);
};

#endif // LOGER_H
