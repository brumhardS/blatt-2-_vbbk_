#ifndef LOGGING_H
#define LOGGING_H

#include <QString>
#include <QTime>



class Logging
{
public:
    Logging();

    static void logStatus(QString status);
    static void logWarning(QString warning);
    static void logError(QString error);
};

#endif // LOGGING_H
