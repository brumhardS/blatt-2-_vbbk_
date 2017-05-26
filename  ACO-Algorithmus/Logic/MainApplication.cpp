#include "MainApplication.h"

MainApplication::MainApplication()
{
    list = new QList<Ant*>();
    for(int i= 0; i < ANT_COUNT; i++)
    {
        list->append(new Ant(new QPoint(ANT_COLONY_X, ANT_COLONY_Y)));
    }

    for(int i= 0; i < RASTER_X; i++)
    {
        for(int j = 0; j < RASTER_Y; j++)
        {
            raster[i][j] = 1;
            pheromone[i][j] = 1;
        }
    }
}

QList<Ant*>* MainApplication::getList() const
{
    return list;
}

void MainApplication::setList(QList<Ant*> *value)
{
    list = value;
}
