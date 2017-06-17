#include "Ant.h"
#include "configuration.h"

//
Ant::Ant(QPoint *actualPos) :
   isSearchFeed(true)
{    
    path = QList<QPoint*>();
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

QList<QPoint*> Ant::getPath()
{
    return path;
}

QPoint * Ant::getPosition()
{
    return path.back();
}


void Ant::setPath(const QList<QPoint*> &value)
{
    path = value;
}

void Ant::reset()
{
    QPoint * current = getPosition();
    path.clear();
    path.append(current);
}

void Ant::resetToStart()
{
    QPoint * current = path.first();
    path.clear();
    path.append(current);

}

void Ant::setID(int id)
{
    Logging::logStatus(QString("SET-ID: %1").arg(id));
    antID = id;
}


void Ant::step(float pheromones[8]){ // 8 -> Nachbarn

    float sumP = 0;

    for(int i = 0; i < 8; i++)
    {
       sumP += pheromones[i];
    }

    float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
    float random = 0 + scale * ( sumP );

    float threshold = 0;

    int position = 0;

    for(int i = 0; i < 8; i++)
    {
       threshold += pheromones[i];
       if(random < threshold)
       {
           position = i;
           break;
       }
    }

    int x = path.back()->rx();
    int y = path.back()->ry();

    QPoint * newPosition;

    switch(position)
    {
        case 0: newPosition = new QPoint(x, y - 1);
                break;
        case 1: newPosition = new QPoint(x + 1, y - 1);
                break;
        case 2: newPosition = new QPoint(x + 1, y);
                break;
        case 3: newPosition = new QPoint(x + 1, y + 1);
                break;
        case 4: newPosition = new QPoint(x, y + 1);
                break;
        case 5: newPosition = new QPoint(x - 1, y + 1);
                break;
        case 6: newPosition = new QPoint(x - 1, y);
                break;
        case 7: newPosition = new QPoint(x - 1, y - 1);

    }
    if((newPosition->rx() <= RASTER_X && newPosition->rx()>= 0) &&
            (newPosition->ry() <= RASTER_Y && newPosition->ry() >=0))
    {
        path.append(newPosition);
    }
    else
    {
        Logging::logWarning(QString("ANT-NR: %5: Set old Position, because the next Position is INVALID!!!!! "
                                    "--> old Positioni: x = %1, y= %2 --> "
                                    "new Position: x = %3, y= %4 ")
                            .arg(newPosition->rx())
                            .arg(newPosition->ry())
                            .arg(x)
                            .arg(y)
                            .arg(antID));
        path.append(new QPoint(ANT_COLONY_X,ANT_COLONY_Y));
    }
}

void Ant::sendSignal()
{
    // Zuerst wird die Position neu berechnet, in Path gesetzt und erst dann wird das Signal gesendet!
    QPoint *point = path.at(path.size()-1);
    emit move(point);

    //actualPos = point;
}
