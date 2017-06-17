#include "MainApplication.h"

MainApplication::MainApplication()
{
    list = new QList<Ant*>;

    for(int i= 0; i < RASTER_X; i++)
    {
        for(int j = 0; j < RASTER_Y; j++)
        {
            raster[i][j] = 1;

            for(int k = 0; k < 8; k++) {

                pheromone[i][j][k] = 1;
            }
        }
    }

    raster[ANT_COLONY_X][ANT_COLONY_Y] = ANTCOLONY;
    raster[BERRY_POSITION_X][BERRY_POSITION_Y] = BERRY;

    for(int i = 0; i < RASTER_X; i++)
    {
        pheromone[i][0][0] = 0;
        pheromone[i][0][1] = 0;
        pheromone[i][0][7] = 0;
        pheromone[i][RASTER_Y - 1][3] = 0;
        pheromone[i][RASTER_Y - 1][4] = 0;
        pheromone[i][RASTER_Y - 1][5] = 0;
    }

    for(int i = 0; i < RASTER_Y; i++)
    {
        pheromone[0][i][5] = 0;
        pheromone[0][i][6] = 0;
        pheromone[0][i][7] = 0;
        pheromone[RASTER_X - 1][i][1] = 0;
        pheromone[RASTER_X - 1][i][2] = 0;
        pheromone[RASTER_X - 1][i][3] = 0;
    }


    list = new QList<Ant*>();
    for(int i= 0; i < ANT_COUNT; i++)
    {
        list->append(new Ant(new QPoint(ANT_COLONY_X, ANT_COLONY_Y)));
    }



}

MainApplication::~MainApplication()
{
    delete list;
}

QList<Ant*>* MainApplication::getList() const
{
    return list;
}

void MainApplication::setList(QList<Ant*> *value)
{
    list = value;
}

float* MainApplication::pheromonesFor(Ant * ant){
    int x = ant->getPosition()->rx();
    int y = ant->getPosition()->ry();
    return pheromone[x][y];
}

bool MainApplication::isAtFood(Ant *ant)
{
    return raster[ant->getPosition()->rx()][ant->getPosition()->ry()] == BERRY;
}

bool MainApplication::isAtHome(Ant *ant)
{
    return raster[ant->getPosition()->rx()][ant->getPosition()->ry()] == ANTCOLONY;
}

void MainApplication::updatePheromones(Ant *ant)
{
    QList<QPoint*> path = ant->getPath();

    if(path.size() > shortestPath) return;

    shortestPath = path.size();

    qDebug() << "updating Pheromones";

    for(int i = 0; i < RASTER_X; i++)
    {
        for(int j = 0; j < RASTER_Y; j++)
        {
            for(int k = 0; k < 8; k ++)
            {
                pheromone[i][j][k] = qMax(pheromone[i][j][k] * PHEROMONE_DECREASE, 0.1);
            }
        }
    }

    for(int i = 0; i < path.size() - 2; i++)
    {
        QPoint * p1 = path.at(i);
        QPoint * p2 = path.at(i+1);
        QPoint diff = *p2 - *p1;
        pheromone[p1->rx()][p1->ry()][pheromoneIndexForStep(&diff)] = pheromone[p1->rx()][p1->ry()][pheromoneIndexForStep(&diff)] * PHEROMONE_INCREASE;

    }
}

int MainApplication::pheromoneIndexForStep(QPoint * point)
{
    int x = point->rx();
    int y = point->ry();

    if(x == 0 && y == -1) return 0;
    if(x == 1 && y == -1) return 1;
    if(x == 1 && y == 0) return 2;
    if(x == 1 && y == 1) return 3;
    if(x == 0 && y == 1) return 4;
    if(x == -1 && y == 1) return 5;
    if(x == -1 && y == 0) return 6;
    return 7;
}


void MainApplication::run(){

    std::srand(std::time(0));

    std::chrono::system_clock::time_point next = std::chrono::system_clock::now();
    next += std::chrono::milliseconds(STEP_CLOCK);

    while(true){
        for (int i = 0; i < list->size(); i++) {
            Ant * currentAnt = list->at(i);

            if(isAtHome(currentAnt))
            {
                if(currentAnt->getIsSearchFeed())
                {
                    currentAnt->reset();

                } else
                {
                    //update pheromons invers
                    //reset
                    //change direction
                }

            }

            if(isAtFood(currentAnt))
            {
                if(currentAnt->getIsSearchFeed())
                {
                    qDebug() << "SUCCESS!" << " path length: " << currentAnt->getPath().size();
                    updatePheromones(currentAnt);
                    currentAnt->resetToStart();

                } else
                {
                   // currentAnt->reset();
                }
            }



            currentAnt->step(pheromonesFor(currentAnt));



        }

        std::this_thread::sleep_until(next);

        for (int i = 0; i < list->size(); i++) {

            Ant * currentAnt = list->at(i);

            currentAnt->sendSignal();


        }

        next += std::chrono::milliseconds(STEP_CLOCK);

        // todo calculate new podsitions
        // check if ant reached destination or origin
        // update all ants
    }
}

