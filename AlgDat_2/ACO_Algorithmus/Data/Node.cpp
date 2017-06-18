#include "Node.h"

Node::Node(int x, int y, int type, float valueOfPheromone)
{
   xValue = x;
   yValue = y;
   nodeType = type;
   pheromone = valueOfPheromone;
}

Node::Node(int x, int y, int type)
{
    xValue = x;
    yValue = y;
    nodeType = type;
}

int Node::getType()
{
    return type;
}

void Node::setPheromone(float value)
{
    pheromone = value;
}

float Node::getPheromone()
{
    return pheromone;
}
