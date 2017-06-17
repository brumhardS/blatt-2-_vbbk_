#include "Logging.h"
#include <QDebug>

Logging::Logging()
{
}

void Logging::logStatus(QString status)
{
    qDebug() << QString("TIME: ")
                .append(QTime::currentTime().toString())
                .append(" STATUS: ")
                .append(status);
}

void Logging::logWarning(QString warning)
{
    qDebug() << QString("TIME: ")
                .append(QTime::currentTime().toString())
                .append(" WARNING: ")
                .append(warning);
}

void Logging::logError(QString error)
{
    qDebug() << QString("TIME: ")
                .append(QTime::currentTime().toString())
                .append(" ERROR: ")
                .append(error);
}
