#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <qlist.h>

#include <Gui/AntGraphic.h>
#include <Gui/MainWindow.h>

#include <Data/Ant.h>

#define ANT_COUNT 10
#define BERRY_COUNT 1

#define RASTER_X 19
#define RASTER_Y 19

#define PATH 1
#define BERRY 2
#define ANTCOLONY 3
#define PHEROMONE 1

#define BERRY_POSITION_X 10
#define BERRY_POSITION_Y 10

#define ANT_COLONY_X 0
#define ANT_COLONY_Y 20

class MainApplication : public QObject
{
    Q_OBJECT
public:

    MainApplication();
    QList<Ant*> *list;

    int raster[RASTER_X][RASTER_Y];
    float pheromone[RASTER_X][RASTER_Y];
    QList<Ant *> *getList() const;
    void setList(QList<Ant *> *value);
};

#endif // MAINAPPLICATION_H
