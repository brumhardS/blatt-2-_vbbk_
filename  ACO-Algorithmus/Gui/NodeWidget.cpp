#include "NodeWidget.h"

NodeWidget::NodeWidget()
{
    node = new Node(0,0);
    setFixedSize(10,10);
}

void NodeWidget::setPosX(int posX)
{
    node->setPosX(posX);
}

void NodeWidget::setPosY(int posY)
{
    node->setPosY(posY);
}

void NodeWidget::setPheromone(int value)
{
    node->setValueOfPheromone(value);
}

Node *NodeWidget::getNode() const
{
    return node;
}
