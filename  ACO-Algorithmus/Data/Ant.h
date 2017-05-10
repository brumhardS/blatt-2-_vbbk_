#ifndef ANT_H
#define ANT_H

#include <Gui/AntGraphic.h>



class Ant
{
public:
    Ant(AntGraphic graphic);

    void setPheromone(int value);
    void selectNextNode();
private:
    AntGraphic antGraphic;

    int shortestPath;
    int actualPath;

    // Richtung --> true: Futtersuche, false: Rückweg!
    bool isSearchFeed;


};

#endif // ANT_H
