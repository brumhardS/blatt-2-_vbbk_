#ifndef NODEWIDGET_H
#define NODEWIDGET_H

#include <QVBoxLayout>
#include <QWidget>

#include <Data/Node.h>

class NodeWidget : public QWidget
{
    Q_OBJECT
public:
    NodeWidget();

    //Setze die Werte sofort in der "Node" Klasse!
    void setPosX(int posX);
    void setPosY(int posY);
    void setPheromone(int value);

    Node *getNode() const;

private:
    Node *node;
};

#endif // NODEWIDGET_H
