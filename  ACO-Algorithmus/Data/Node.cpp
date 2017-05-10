#include "Node.h"

Node::Node()
{

}

int Node::getValueOfPheromone() const
{
    return valueOfPheromone;
}

void Node::setValueOfPheromone(int value)
{
    valueOfPheromone = value;
}
