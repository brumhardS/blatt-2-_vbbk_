#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <chrono>
#include <thread>
#include <qlist.h>
#include <QDateTime>
#include <random>

#include <Gui/AntGraphic.h>
#include <Gui/MainWindow.h>

#include <Data/Ant.h>

#define PHEROMONE_INCREASE 10.0
#define PHEROMONE_DECREASE 0.9

#define ANT_COUNT 200
#define BERRY_COUNT 1

#define STEP_CLOCK 100

#define RASTER_X 20
#define RASTER_Y 20

#define PATH 1
#define BERRY 2
#define ANTCOLONY 3

#define BERRY_POSITION_X 15
#define BERRY_POSITION_Y 15

#define ANT_COLONY_X 5
#define ANT_COLONY_Y 5

class MainApplication : public QObject
{
    Q_OBJECT
public:

    MainApplication();
    ~MainApplication();
    QList<Ant*> *list;

    int raster[RASTER_X][RASTER_Y];
    float pheromone[RASTER_X][RASTER_Y][8];
    QList<Ant *> *getList() const;
    void setList(QList<Ant *> *value);
    void run();
    int shortestPath = INT_MAX;

private:
    float* pheromonesFor(Ant * ant);

    bool isAtFood(Ant * ant);

    bool isAtHome(Ant * ant);

    void updatePheromones(Ant * ant);

    int pheromoneIndexForStep(QPoint * point);

};

#endif // MAINAPPLICATION_H
