#include "Node.h"

Node::Node(int posX, int posY)
{
    this->posX = posX;
    this->posX = posY;
}

int Node::getValueOfPheromone() const
{
    return valueOfPheromone;
}

void Node::setValueOfPheromone(int value)
{
    valueOfPheromone = value;
}

int Node::getPosX() const
{
    return posX;
}

void Node::setPosX(int value)
{
    posX = value;
}

int Node::getPosY() const
{
    return posY;
}

void Node::setPosY(int value)
{
    posY = value;
}

Node *Node::getLeft() const
{
    return left;
}

void Node::setLeft(Node *value)
{
    left = value;
}

Node *Node::getRight() const
{
    return right;
}

void Node::setRight(Node *value)
{
    right = value;
}

Node *Node::getButtom() const
{
    return buttom;
}

void Node::setButtom(Node *value)
{
    buttom = value;
}

Node *Node::getTop() const
{
    return top;
}

void Node::setTop(Node *value)
{
    top = value;
}

Node *Node::getTopRight() const
{
    return topRight;
}

void Node::setTopRight(Node *value)
{
    topRight = value;
}

Node *Node::getTopLeft() const
{
    return topLeft;
}

void Node::setTopLeft(Node *value)
{
    topLeft = value;
}

Node *Node::getButtomRight() const
{
    return buttomRight;
}

void Node::setButtomRight(Node *value)
{
    buttomRight = value;
}

Node *Node::getButtomLeft() const
{
    return buttomLeft;
}

void Node::setButtomLeft(Node *value)
{
    buttomLeft = value;
}
