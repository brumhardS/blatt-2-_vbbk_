#ifndef STICK_H
#define STICK_H

#include "BasicGraphicItem.h"

#include <QGraphicsItem>



class StickGrafic : public BasicGraphicItem
{
public:
    StickGrafic();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // STICK_H
