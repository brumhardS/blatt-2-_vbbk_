#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QWidget>



class Node
{
public:
    Node();

    int getValueOfPheromone() const;
    void setValueOfPheromone(int value);

private:
    int valueOfPheromone;

    // All eight eighbours of this node.
    Node *left;
    Node *right;
    Node *buttom;
    Node *top;
    Node *topRight;
    Node *topLeft;
    Node *buttomRight;
    Node *buttomLeft;

    // Property of this node
    bool isFreeToGo;
};

#endif // NODE_H
