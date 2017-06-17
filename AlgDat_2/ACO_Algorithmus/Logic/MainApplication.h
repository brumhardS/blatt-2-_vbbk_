#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <chrono>
#include <thread>
#include <qlist.h>
#include <QDateTime>
#include <random>
#include "Configuration.h"

#include <Gui/AntGraphic.h>
#include <Gui/MainWindow.h>

#include <Data/Ant.h>

#include <QThread>

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

    int shortestPath = INT_MAX;

public slots:
    void run();

signals:
    void finished();
    void error(QString err);

private:
    void initializeRaster();

    void initializePheromone();

    float *pheromonesFor(Ant * ant);

    bool isAtFood(Ant * ant);

    bool isAtHome(Ant * ant);

    void updatePheromones(Ant * ant);

    int pheromoneIndexForStep(QPoint * point);

};

#endif // MAINAPPLICATION_H
