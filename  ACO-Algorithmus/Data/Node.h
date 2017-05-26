#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QWidget>



class Node
{
public:

    Node(int posX, int posY);

    int getValueOfPheromone() const;
    void setValueOfPheromone(int value);

    int getPosX() const;
    void setPosX(int value);

    int getPosY() const;
    void setPosY(int value);

    Node *getLeft() const;
    void setLeft(Node *value);

    Node *getRight() const;
    void setRight(Node *value);

    Node *getButtom() const;
    void setButtom(Node *value);

    Node *getTop() const;
    void setTop(Node *value);

    Node *getTopRight() const;
    void setTopRight(Node *value);

    Node *getTopLeft() const;
    void setTopLeft(Node *value);

    Node *getButtomRight() const;
    void setButtomRight(Node *value);

    Node *getButtomLeft() const;
    void setButtomLeft(Node *value);

private:
    int valueOfPheromone;
    int posX;
    int posY;

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
