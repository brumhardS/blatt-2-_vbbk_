#include "Ant.h"
//
Ant::Ant(QPoint *actualPos) : actualPos(actualPos),
   isSearchFeed(false)
{    
    path.append(actualPos);
}

int Ant::getPathLength()
{
    return path.size();
}


bool Ant::getIsSearchFeed()
{
    return isSearchFeed;
}

void Ant::setIsSearchFeed(bool value)
{
    isSearchFeed = value;
}

QList<QPoint*> Ant::getPath() const
{
    return path;
}

void Ant::setPath(const QList<QPoint*> &value)
{
    path = value;
}

void Ant::sendSignal()
{
    // Zuerst wird die Position neu berechnet, in Path gesetzt und erst dann wird das Signal gesendet!
    QPoint *point = path.at(path.size()-1);
    emit move(point);






    actualPos = point;
}
