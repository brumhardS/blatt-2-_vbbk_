#ifndef ANT_H
#define ANT_H

#include <Gui/AntGraphic.h>


class Ant : public QObject
{
    Q_OBJECT

public:

    Ant(QPoint *actualPos);

    bool getIsSearchFeed();
    void setIsSearchFeed(bool value);

    int getPathLength();

    QList<QPoint *> getPath() const;
    void setPath(const QList<QPoint *> &value);

    void sendSignal();

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
