#ifndef ANT_H
#define ANT_H

#include <ctime>
#include <cstdlib>
#include <Gui/AntGraphic.h>
#include <QDebug>
#include <random>


class Ant : public QObject
{
    Q_OBJECT

public:

    Ant(QPoint *actualPos);

    bool getIsSearchFeed();
    void setIsSearchFeed(bool value);

    int getPathLength();

    QList<QPoint *> getPath();

    QPoint * getPosition();


    void setPath(const QList<QPoint *> &value);

    void sendSignal();

    void step(float pheromones[8]);

    void reset();

    void resetToStart();


private:
    int actualPathCount;

    QList<QPoint*> path;

    QPoint *actualPos;

    // Richtung --> true: Futtersuche, false: Rückweg!
    bool isSearchFeed;

signals:
    void move(QPoint *point);
};

#endif // ANT_H
