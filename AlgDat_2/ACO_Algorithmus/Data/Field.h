#ifndef FIELD_H
#define FIELD_H

#include "Node.h"

#include <QList>



class Field
{
public:
    Field();
    Node *getNode(int x, int y);
    float *getNeighboursPheromone(int x, int y);

private:
    void init();
    QList<Node*> allNods;
};

#endif // FIELD_H
