#ifndef NODE_H
#define NODE_H


class Node
{
public:
    Node(int x, int y, int type, float valueOfPheromone);
    Node(int x, int y, int type);
    int getType();
    void setPheromone(float value);
    float getPheromone();

private:
    int xValue;
    int yValue;
    int nodeType;
    float pheromone;

};

#endif // NODE_H
